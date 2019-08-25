//
//  TestDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/7/7.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "TestDemo.hpp"
#include <iostream>

using namespace std;

struct Test {
    int (*FindClass)(char *name);
};

int jni_FindClass(char *name)
{
    return 0;
}

struct Test T1 = {
    jni_FindClass
};

void TestDemo::run_test(void *arg) {
    
    char *name = "guanz";
    
    T1.FindClass(name);
    
    cout << "print test demo" << endl;
    
    cout << *(int *)arg << endl;
}
