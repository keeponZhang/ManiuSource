package com.maniu.videochatb;

import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements SocketLive.SocketCallback {
    SurfaceView removeSurfaceView;
    LocalSurfaceView localSurfaceView;
    DecodecPlayerLiveH265 decodecPlayerLiveH265;
    Surface surface;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView() {
      removeSurfaceView = findViewById(R.id.removeSurfaceView);
      localSurfaceView = findViewById(R.id.localSurfaceView);
      removeSurfaceView.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(@NonNull SurfaceHolder holder) {
                surface = holder.getSurface();
                decodecPlayerLiveH265 = new DecodecPlayerLiveH265();
                decodecPlayerLiveH265.initDecoder(surface);

            }
            @Override
            public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {

            }
            @Override
            public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
            }
        });

    }
    public void connect(View view) {
        localSurfaceView.startCaptrue(this);
    }
//    socket 接收到了另外一段的数据
    @Override
    public void callBack(byte[] data) {

        if (decodecPlayerLiveH265 != null) {
            decodecPlayerLiveH265.callBack(data);
        }

    }
}