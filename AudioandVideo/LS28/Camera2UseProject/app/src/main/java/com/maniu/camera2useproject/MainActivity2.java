package com.maniu.camera2useproject;

import android.Manifest;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.ImageFormat;
import android.graphics.Rect;
import android.graphics.SurfaceTexture;
import android.graphics.YuvImage;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.util.Size;
import android.view.TextureView;
import android.widget.ImageView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class MainActivity2 extends AppCompatActivity implements TextureView.SurfaceTextureListener, Camera2Helper.Camera2Listener {
    private TextureView textureView;
    Camera2Helper camera2Helper;
    // 图像帧数据，全局变量避免反复创建，降低gc频率
    private byte[] nv21;
    byte[] nv21_rotated;
    // 用于显示原始预览数据
    private ImageView ivOriginFrame;
    // 用于显示和预览画面相同的图像数据
    private ImageView ivPreviewFrame;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textureView = findViewById(R.id.texture_preview);
        textureView.setSurfaceTextureListener(this);
    }

    @Override
    public void onSurfaceTextureAvailable(@NonNull SurfaceTexture surface, int width, int height) {
        if (!checkPermissions()) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CAMERA}, 1);
        } else {
            initCamera();
        }
    }


    void initCamera() {
        camera2Helper = new Camera2Helper(this);
        camera2Helper.start( textureView);
    }
    private boolean checkPermissions() {
        boolean allGranted = true;
         allGranted &= ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && checkSelfPermission(
                Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            requestPermissions(new String[]{
                    Manifest.permission.READ_EXTERNAL_STORAGE,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE
            }, 1);
        }
        return allGranted;
    }
    @Override
    public void onSurfaceTextureSizeChanged(@NonNull SurfaceTexture surface, int width, int height) {

    }

    @Override
    public boolean onSurfaceTextureDestroyed(@NonNull SurfaceTexture surface) {
        return false;
    }

    @Override
    public void onSurfaceTextureUpdated(@NonNull SurfaceTexture surface) {

    }

    @Override
    public void onPreview(byte[] y, byte[] u, byte[] v, Size previewSize, int stride) {
        if (nv21 == null) {
            nv21 = new byte[stride * previewSize.getHeight() * 3 / 2];
            nv21_rotated=new byte[stride * previewSize.getHeight() * 3 / 2];
        }
        ImageUtil.yuvToNv21(y, u, v, nv21, stride, previewSize.getHeight());
        ImageUtil.nv21_rotate_to_90(nv21, nv21_rotated,stride,previewSize.getHeight() );
        YuvImage yuvImage = new YuvImage(nv21_rotated, ImageFormat.NV21, previewSize.getHeight(), previewSize.getWidth(),  null);
        // ByteArrayOutputStream的close中其实没做任何操作，可不执行
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();

        // 由于某些stride和previewWidth差距大的分辨率，[0,previewWidth)是有数据的，而[previewWidth,stride)补上的U、V均为0，因此在这种情况下运行会看到明显的绿边
//                    yuvImage.compressToJpeg(new Rect(0, 0, stride, previewSize.getHeight()), 100, byteArrayOutputStream);

        // 由于U和V一般都有缺损，因此若使用方式，可能会有个宽度为1像素的绿边
        yuvImage.compressToJpeg(new Rect(0, 0, previewSize.getHeight(), previewSize.getWidth()), 100, byteArrayOutputStream);

        // 为了删除绿边，抛弃一行像素
//                    yuvImage.compressToJpeg(new Rect(0, 0, previewSize.getWidth() - 1, previewSize.getHeight()), 100, byteArrayOutputStream);

        byte[] jpgBytes = byteArrayOutputStream.toByteArray();
        BitmapFactory.Options options = new BitmapFactory.Options();
        options.inSampleSize = 4;
        // 原始预览数据生成的bitmap
        final Bitmap originalBitmap = BitmapFactory.decodeByteArray(jpgBytes, 0, jpgBytes.length, options);
        saveBitmap(originalBitmap, new File(Environment.getExternalStorageDirectory(), "orgin.jpg").getAbsolutePath());




    }

    public static void saveBitmap(Bitmap bitmap,String path) {
        String savePath;
        File filePic;
        if (Environment.getExternalStorageState().equals(
                Environment.MEDIA_MOUNTED)) {
            savePath = path;
        } else {
            Log.e("tag", "saveBitmap failure : sdcard not mounted");
            return;
        }
        try {
            filePic = new File(savePath);
            if (!filePic.exists()) {
                filePic.getParentFile().mkdirs();
                filePic.createNewFile();
            }
            FileOutputStream fos = new FileOutputStream(filePic);
            bitmap.compress(Bitmap.CompressFormat.JPEG, 100, fos);
            fos.flush();
            fos.close();
        } catch (IOException e) {
            Log.e("tag", "saveBitmap: " + e.getMessage());
            return;
        }
        Log.i("tag", "saveBitmap success: " + filePic.getAbsolutePath());
    }
}