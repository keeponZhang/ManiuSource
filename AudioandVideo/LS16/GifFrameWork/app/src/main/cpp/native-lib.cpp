#include <jni.h>
#include <string>
#include <android/bitmap.h>
extern "C"{
#include "gif_lib.h"
}
#include <android/log.h>
#define  LOG_TAG    "David"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  dispose(ext) (((ext)->Bytes[0] & 0x1c) >> 2)
#define  trans_index(ext) ((ext)->Bytes[3])
#define  transparency(ext) ((ext)->Bytes[0] & 1)
//8  1   16  2  24  3
struct GifBean{
    int current_frame;
    int total_frame;
    int *delays;
};
#define  argb(a,r,g,b) ( ((a) & 0xff) << 24 ) | ( ((b) & 0xff) << 16 ) | ( ((g) & 0xff) << 8 ) | ((r) & 0xff)
extern "C"
JNIEXPORT jlong JNICALL
Java_com_maniu_gifframework_GifHandler_loadGif(JNIEnv *env, jclass clazz, jstring path_) {
    const char *path = env->GetStringUTFChars(path_, 0);
//    path   java   --
    int Erro;//打开失败还是成功
    GifFileType * gifFileType= DGifOpenFileName(path, &Erro);

//初始化缓冲区  数组 SaveImages
    DGifSlurp(gifFileType);
    GifBean *gifBean = static_cast<GifBean *>(malloc(sizeof(GifBean)));
    memset(gifBean, 0, sizeof(GifBean));
    gifFileType->UserData = gifBean;
    gifBean->current_frame = 0;
//    总帧数
    gifBean->total_frame = gifFileType->ImageCount;

    env->ReleaseStringUTFChars(path_, path);
    return (jlong)(gifFileType);
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_getWidth(JNIEnv *env, jclass clazz, jlong gif_hander) {
    // TODO: implement getWidth()
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_hander);
    return gifFileType->SWidth;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_getHeight(JNIEnv *env, jclass clazz, jlong gif_hander) {
    // TODO: implement getHeight()
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_hander);
    return gifFileType->SHeight;
}

int drawFrame(GifFileType* gif,AndroidBitmapInfo  info,   void* pixels,  bool force_dispose_1) {
    GifColorType *bg;

    GifColorType *color;

    SavedImage * frame;

    ExtensionBlock * ext = 0;

    GifImageDesc * frameInfo;

    ColorMapObject * colorMap;

    int *line;

    int width, height,x,y,j,loc,n,inc,p;

    void* px;

    GifBean *gifBean = static_cast<GifBean *>(gif->UserData);

    width = gif->SWidth;

    height = gif->SHeight;
    frame = &(gif->SavedImages[gifBean->current_frame]);

    frameInfo = &(frame->ImageDesc);

    if (frameInfo->ColorMap) {

        colorMap = frameInfo->ColorMap;

    } else {

        colorMap = gif->SColorMap;

    }



    bg = &colorMap->Colors[gif->SBackGroundColor];



    for (j=0; j<frame->ExtensionBlockCount; j++) {

        if (frame->ExtensionBlocks[j].Function == GRAPHICS_EXT_FUNC_CODE) {

            ext = &(frame->ExtensionBlocks[j]);

            break;

        }

    }
    // For dispose = 1, we assume its been drawn
    px = pixels;
    if (ext && dispose(ext) == 1 && force_dispose_1 && gifBean->current_frame > 0) {
        gifBean->current_frame=gifBean->current_frame-1,
                drawFrame(gif , info, pixels,  true);
    }

    else if (ext && dispose(ext) == 2 && bg) {

        for (y=0; y<height; y++) {

            line = (int*) px;

            for (x=0; x<width; x++) {

                line[x] = argb(255, bg->Red, bg->Green, bg->Blue);

            }

            px = (int *) ((char*)px + info.stride);

        }

    } else if (ext && dispose(ext) == 3 && gifBean->current_frame > 1) {
        gifBean->current_frame=gifBean->current_frame-2,
                drawFrame(gif,  info, pixels,  true);

    }
    px = pixels;
    if (frameInfo->Interlace) {

        n = 0;

        inc = 8;

        p = 0;

        px = (int *) ((char*)px + info.stride * frameInfo->Top);

        for (y=frameInfo->Top; y<frameInfo->Top+frameInfo->Height; y++) {

            for (x=frameInfo->Left; x<frameInfo->Left+frameInfo->Width; x++) {

                loc = (y - frameInfo->Top)*frameInfo->Width + (x - frameInfo->Left);

                if (ext && frame->RasterBits[loc] == trans_index(ext) && transparency(ext)) {

                    continue;

                }



                color = (ext && frame->RasterBits[loc] == trans_index(ext)) ? bg : &colorMap->Colors[frame->RasterBits[loc]];

                if (color)

                    line[x] = argb(255, color->Red, color->Green, color->Blue);

            }

            px = (int *) ((char*)px + info.stride * inc);

            n += inc;

            if (n >= frameInfo->Height) {

                n = 0;

                switch(p) {

                    case 0:

                        px = (int *) ((char *)pixels + info.stride * (4 + frameInfo->Top));

                        inc = 8;

                        p++;

                        break;

                    case 1:

                        px = (int *) ((char *)pixels + info.stride * (2 + frameInfo->Top));

                        inc = 4;

                        p++;

                        break;

                    case 2:

                        px = (int *) ((char *)pixels + info.stride * (1 + frameInfo->Top));

                        inc = 2;

                        p++;

                }

            }

        }

    }

    else {

        px = (int *) ((char*)px + info.stride * frameInfo->Top);

        for (y=frameInfo->Top; y<frameInfo->Top+frameInfo->Height; y++) {

            line = (int*) px;

            for (x=frameInfo->Left; x<frameInfo->Left+frameInfo->Width; x++) {

                loc = (y - frameInfo->Top)*frameInfo->Width + (x - frameInfo->Left);

                if (ext && frame->RasterBits[loc] == trans_index(ext) && transparency(ext)) {

                    continue;

                }

                color = (ext && frame->RasterBits[loc] == trans_index(ext)) ? bg : &colorMap->Colors[frame->RasterBits[loc]];

                if (color)

                    line[x] = argb(255, color->Red, color->Green, color->Blue);

            }

            px = (int *) ((char*)px + info.stride);

        }
    }
    GraphicsControlBlock gcb;//获取控制信息
    DGifSavedExtensionToGCB(gif,gifBean->current_frame,&gcb);
    int delay=gcb.DelayTime * 10;
    LOGE("delay %d",delay);
    return delay;
}
int drawFrame1(GifFileType* gifFileType, AndroidBitmapInfo info, void *pixels) {
    GifBean *gifBean = static_cast<GifBean *>(gifFileType->UserData);
    //当前帧 一定要拿到         拿到当前帧   直接
    SavedImage savedImage = gifFileType->SavedImages[gifBean->current_frame];
//    图像分成两部分  像素   一部分是 描述
    GifImageDesc frameInfo=savedImage.ImageDesc;
    ColorMapObject *colorMapObject = frameInfo.ColorMap;
//    像素
//    savedImage.RasterBits[i];
//FFmpeg  视频
//记录每一行的首地址
//bitmap
    int* px = (int *)pixels;

//    临时 索引
    int *line;
//    索引
    int  pointPixel;
    GifByteType  gifByteType;
//操作   解压
    GifColorType gifColorType;
    for (int y =frameInfo.Top ; y<frameInfo.Top+frameInfo.Height; ++y) {
//每次遍历行    首地址 传给line
        line = px;
        for (int x =  frameInfo.Left; x < frameInfo.Left + frameInfo.Width ; ++x) {
//            定位像素  索引
            pointPixel = (y - frameInfo.Top) * frameInfo.Width + (x - frameInfo.Left);
//            是 1不是2  压缩
            gifByteType=savedImage.RasterBits[pointPixel];
            gifColorType= colorMapObject->Colors[gifByteType];
//line 进行复制   0  255  屏幕有颜色 line
            line[x] = argb(255, gifColorType.Red, gifColorType.Green, gifColorType.Blue);
        }
//遍历条件     转到下一行
        px = (int *) ((char *) px + info.stride);
    }
    GraphicsControlBlock gcb;//获取控制信息
    DGifSavedExtensionToGCB(gifFileType,gifBean->current_frame,&gcb);
    int delay=gcb.DelayTime * 10;
    LOGE("delay %d",delay);
    return delay;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_maniu_gifframework_GifHandler_updateFrame(JNIEnv *env, jclass clazz, jlong gif_point,
                                                   jobject bitmap) {
//    bitmap.get
    GifFileType *gifFileType = reinterpret_cast<GifFileType *>(gif_point);
    int width = gifFileType->SWidth;

    int height = gifFileType->SHeight;
//    还有另外一种    根据bitmap 获取
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bitmap, &info);
    int *pixels=NULL;
//bitmap--->像素二维数组    ----- 锁住当前bitmap
    AndroidBitmap_lockPixels(env, bitmap, reinterpret_cast<void **>(&pixels));
//    绘制颜色
//    pixels={{0,0,0,0},{0,0,0,0}};
    int delay=drawFrame(gifFileType, info, pixels ,false);
    AndroidBitmap_unlockPixels(env, bitmap);
    GifBean *gifBean = static_cast<GifBean *>(gifFileType->UserData);
    gifBean->current_frame++;
    if (gifBean->current_frame >gifBean->total_frame - 1) {
        gifBean->current_frame = 0;
    }
    return delay;
}