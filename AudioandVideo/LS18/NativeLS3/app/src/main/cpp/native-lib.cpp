#include <jni.h>
#include <string>
#include <android/log.h>

jstring david(
        JNIEnv *env,
        jobject job) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

static const JNINativeMethod gMethods[] = {
        {
                "stringFromJNI1111",
                "()Ljava/lang/String;",
                (jstring *) david
        }
};


//实现动态注册  java虚拟机引擎 JavaVM
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    __android_log_print(ANDROID_LOG_INFO, "native", "Jni_OnLoad");
    JNIEnv *env = NULL;
    //GetEnv接受的是一个二级指针，所以这里要传地址，GetEnv会改变外面的值
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    //接下来的就是成功JNIEnv
    jclass clazz = env->FindClass("com/maniu/nativels3/MainActivity");
    //第一个参数要传类，第三个参数传方法个数
    env->RegisterNatives(clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0]));
    return JNI_VERSION_1_4;
}