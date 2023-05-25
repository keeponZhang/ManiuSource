package com.maniu.gifframework;

import android.graphics.Bitmap;

public class GifHandler {
    long gifHandler;//地址   指针类型    大小一样的 纽带

    static {
        System.loadLibrary("native-lib");
    }

    public int getWidth() {
        return getWidth(gifHandler);
    }

    public int getHeight() {
        return getHeight(gifHandler);
    }

    public int updateFrame(Bitmap bitmap) {
        return updateFrame(gifHandler, bitmap);
    }

    private GifHandler(long gifHandler) {
        this.gifHandler = gifHandler;
    }

    public static GifHandler load(String path) {
        long gifHandlerLong = loadGif(path);
        GifHandler gifHandler = new GifHandler(gifHandlerLong);
        return gifHandler;
    }

    //   开始加载gif文件  Java+包名+类名+方法名  中间分隔用下划线        参数   第一个 JNIEnv  第二个  如static   class   对象  object
    //   第三个开始是需要传递真正的参数
    public static native long loadGif(String path);

    //    宽 ,把地址传进去了
    public static native int getWidth(long gifHandler);

    //    高 ,把地址传进去了
    public static native int getHeight(long gifHandler);

    // 渲染图片，传到native层会转换成jObject类型，返回是下一帧的时间
    public static native int updateFrame(long gifHandler, Bitmap bitmap);
}
