#include <jni.h>
#include <string>
#include <android/bitmap.h>

//extern "C"告诉编译器是c文件
extern "C" {
#include "gif_lib.h"
}
//16个字节
struct GifBean {
    int current_frame;
    int total_frame;
    int *delays;
};
#define  argb(a, r, g, b) ( ((a) & 0xff) << 24 ) | ( ((b) & 0xff) << 16 ) | ( ((g) & 0xff) << 8 ) | ((r) & 0xff)
extern "C"
JNIEXPORT jlong JNICALL
Java_com_maniu_gifframework_GifHandler_loadGif(JNIEnv *env, jclass clazz, jstring path_) {
    //可以理解为转换器
    const char *path = env->GetStringUTFChars(path_, 0);
    int Error;//打开失败还是成功
    //这里要把地址传进去，返回的也是一个指针，指向结构体
    GifFileType *gifFileType = DGifOpenFileName(path, &Error);

    //初始化缓冲区
    DGifSlurp(gifFileType);
    GifBean *gifBean = static_cast<GifBean *>(malloc(sizeof(GifBean)));
    //清空一下
    //
    memset(gifBean, 0, sizeof(GifBean));
    gifFileType->UserData = gifBean;
    gifBean->current_frame = 0;
    // 总帧数
    gifBean->total_frame = gifFileType->ImageCount;
    //这里要释放掉
    env->ReleaseStringUTFChars(path_, path);
    return (jlong) (gifFileType);
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_getWidth(JNIEnv *env, jclass clazz, jlong gif_handler) {
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_handler);
    return gifFileType->SWidth;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_getHeight(JNIEnv *env, jclass clazz, jlong gif_handler) {
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_handler);
    return gifFileType->SHeight;
}

void drawFrame1(GifFileType *gifFileType, AndroidBitmapInfo info, void *pixels) {
    GifBean *gifBean = static_cast<GifBean *>(gifFileType->UserData);
    //拿到当前帧
    SavedImage savedImage = gifFileType->SavedImages[gifBean->current_frame];
    //图像分成两部分像素,一部分是描述
    GifImageDesc frameInfo = savedImage.ImageDesc;
    ColorMapObject *colorMapObject = frameInfo.ColorMap;
    // 像素
    // savedImage.RasterBits[i];
    //记录每一行的首地址
    //bitmap
    int *px = (int *) pixels;

    // 临时 索引
    int *line;
    //索引
    int pointPixel;
    GifByteType gifByteType;
    //操作解压
    GifColorType gifColorType;
    for (int y = frameInfo.Top; y < frameInfo.Top + frameInfo.Height; ++y) {
    //每次遍历行 首地址 传给line
        line = px;
        for (int x = frameInfo.Left; x < frameInfo.Left + frameInfo.Width; ++x) {
            //定位像素  索引
            pointPixel = (y - frameInfo.Top) * frameInfo.Width + (x - frameInfo.Left);
            //这是压缩数据，不能直接拿来使用
            gifByteType = savedImage.RasterBits[pointPixel];
            gifColorType = colorMapObject->Colors[gifByteType];
            //line 进行复制   0  255  屏幕有颜色 line
            line[x] = argb(255, gifColorType.Red, gifColorType.Green, gifColorType.Blue);
        }
        //遍历条件转到下一行，stride是字节
        px = (int *) ((char *) px + info.stride);
    }

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_updateFrame(JNIEnv *env, jclass clazz, jlong gif_point,
                                                   jobject bitmap) {
    //bitmap.get
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_point);
    //通过gifFileType获得宽高
    int width = gifFileType->SWidth;
    int height = gifFileType->SHeight;


    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bitmap, &info);

    //也可以通过AndroidBitmapInfo得到宽高
    width = info.width;
    height = info.height;

    //把bitmap转换成数组
    void *pixels;
    //bitmap--->像素二维数组    ----- 锁住当前bitmap
    AndroidBitmap_lockPixels(env, bitmap, &pixels);
    //绘制
    drawFrame1(gifFileType, info, pixels);
    AndroidBitmap_unlockPixels(env, bitmap);
    GifBean *gifBean = static_cast<GifBean *>(gifFileType->UserData);
    gifBean->current_frame++;
    if (gifBean->current_frame >= gifBean->total_frame - 1) {
        gifBean->current_frame = 0;
    }
    return 100;
}