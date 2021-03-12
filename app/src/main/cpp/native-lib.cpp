#include <jni.h>
#include <string>

#include <iostream>
#include <ctime>


extern "C" JNIEXPORT jstring JNICALL
Java_com_expleo_ndkdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_expleo_ndkdemo_MainActivity_stringFromExpleo(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from Expleo";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_expleo_ndkdemo_MainActivity_getDateTime(
        JNIEnv *env,
        jobject /* this */) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);
    return env->NewStringUTF(str.data());
}






