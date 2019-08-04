//
//  JvmDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/7/13.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "JvmDemo.hpp"
#include <JavaVM/jni.h>
#include <pthread.h>

void JvmDemo::run()
{
    // 设置JVM参数
    JavaVM *jvm;
    JNIEnv *env;
    
    JavaVMInitArgs args;
    JavaVMOption options[1];
    
    char *optionStr = (char *)malloc(100);
    
    strcpy(optionStr, "-Djava.class.path=~/");
    
    options[0].optionString = optionStr;
    
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    args.options = options;
    args.ignoreUnrecognized = JNI_TRUE;
    
    // 创建JVM环境
    jint vm = JNI_CreateJavaVM(&jvm, (void **) &env, (void *) &args);
    if (vm == JNI_OK) {
        cout << "create jvm successful!!!" << endl;
    } else {
        cout << "create jvm fail" << endl;
        return;
    }
    
    // Find class
    jclass user_class = env->FindClass("Hello");
    if (user_class == NULL) {
        cout << "user class not find!!!" << endl;
        free(optionStr);
        jvm->DestroyJavaVM();
        return;
    } else {
        cout << "find class success" << endl;
    }
    
//    jmethodID currentTimeMillis = env->GetStaticMethodID(user_class, "currentTimeMillis", "()J");
    
//    jlong value;
    
//    value = env->CallStaticLongMethod(user_class, currentTimeMillis);
    
//    cout << value << endl;
    
//    jmethodID user_method = env->GetMethodID(user_class, "test", "()V");
    
//    jmethodID con = env->GetMethodID(user_class,"<init>","()V");
    
//    jobject obj = env->NewObject(user_class, con);
    
//    call method
//    env->CallVoidMethod(obj, user_method);
    
    free(optionStr);
    jvm->DestroyJavaVM();
}

void JvmDemo::run_test(string context)
{
    cout << context.size() << endl;
    
    cout << "\033[33mHello \033[34mworld!\033[0m" << endl;
    
    cout << context << endl;
    
}


void JvmDemo::jvm_print(const char *context)
{
    cout << context << endl;
}

enum Muth {
    one = 1, two, three
};

void JvmDemo::enum_test()
{
//    JvmDemo::_call_stub_entry = 0;
    cout << two << endl;
}

