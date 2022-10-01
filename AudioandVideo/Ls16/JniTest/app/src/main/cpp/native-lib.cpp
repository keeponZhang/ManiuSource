#include <jni.h>
#include <string>


//C++  kotlin  高级语言  gcc       c    java
extern "C" __attribute__ ((visibility ("default"))) jstring JNICALL
 Java_com_maniu_jnitest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "码牛";//栈区
//    hello.c_str() 表示转换成c的字符串数组
    return env->NewStringUTF(hello.c_str());
}

extern "C" __attribute__ ((visibility ("default"))) jstring
Java_com_maniu_jnitest_MainActivity_func1(JNIEnv *env, jobject thiz) {
    std::string hello = "func1";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_maniu_jnitest_MainActivity_func2(JNIEnv *env, jobject thiz) {
    std::string hello = "func2";
    return env->NewStringUTF(hello.c_str());
}

//env  是每个jni函数第一个参数  主线程    JNIEnv 都是同一个

// 子线程 不同线程

//jstring是返回值
extern "C"
JNIEXPORT jstring JNICALL
Java_com_maniu_jnitest_MainActivity_func3(JNIEnv *env, jobject thiz) {
    jclass activityClass=env->GetObjectClass(thiz);
//    java 字符串   object L+/分隔完整类名
    jfieldID idText = env->GetFieldID(activityClass, "text", "Ljava/lang/String;");
    jstring text1 = env->NewStringUTF("native 层修改");
    env->SetObjectField(thiz, idText, text1);



    std::string hello = "func3";
    return env->NewStringUTF(hello.c_str());
}
//JNIEXPORT是一个宏
//C  不会出错  运行时会报错
extern "C"
JNIEXPORT jstring JNICALL
Java_com_maniu_jnitest_MainActivity_func4(JNIEnv *env, jobject thiz) {
    jclass activityClass=env->GetObjectClass(thiz);
//    java 字符串  (I)V返回值在后面
    jmethodID idText = env->GetMethodID(activityClass, "callBack", "(I)V");
//   返回值是Void，所以是CallVoidMethod
    env->CallVoidMethod(thiz, idText, 2);
    std::string hello = "func3";
    return env->NewStringUTF(hello.c_str());
}