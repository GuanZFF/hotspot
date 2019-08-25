//
//  SpinLock.cpp
//  hotspot
//
//  Created by GuanZF on 2019/7/17.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "SpinLock.hpp"
#include <iostream>
#include <pthread.h>

using namespace std;

typedef int jint;

// 联合体每个数据的开始地址相同
union UNION_TEST {
    int a;
    bool b;
    char c;
};

// 枚举实现逻辑
enum ENUM_TEST {
    T1 = 100, T2 = 200
};

void SpinLock::run()
{
    jint i = 1234;
    
    cout << i << endl;
    
#define TEST 123
    
    cout << TEST << endl;
    
#ifdef TEST
    cout << "code 1" << endl;
#endif
    
#ifndef TEST
    cout << "code 2" << endl;
#endif
    
    cout << "test" << endl;
    
    UNION_TEST u;
    u.a = 1;
    u.b = false;
    
    cout << u.b << endl;

    ENUM_TEST e = T1;
    
    cout << e << endl;
}
