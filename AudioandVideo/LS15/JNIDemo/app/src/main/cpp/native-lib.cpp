#include <jni.h>
#include <string>

jclass jclass1;
extern "C" JNIEXPORT jstring JNICALL
Java_com_maniu_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_maniu_jnidemo_MainActivity_memery(JNIEnv *env, jobject thiz) {
    //这种系统会帮你回收（因为不是malloc或者new出来的）
    jclass tempClass = env->FindClass("java/lang/String");
    //变成全局的，这样这个方法执行后，jclass1才能继续被其他地方使用
    jclass1 = static_cast<jclass>(env->NewWeakGlobalRef(tempClass));
    //jclass1 = static_cast<jclass>(env->NewGlobalRef(tempClass));

}extern "C"
JNIEXPORT void JNICALL
Java_com_maniu_jnidemo_MainActivity_destroy(JNIEnv *env, jobject thiz) {
//    env->DeleteGlobalRef(jclass1);
    env->DeleteWeakGlobalRef(jclass1);
    jclass1 = NULL;

}




extern "C"
JNIEXPORT void JNICALL
Java_com_maniu_jnidemo_MainActivity_memery1(JNIEnv *env, jobject thiz) {
    if (jclass1) {

    } else {

    }
}