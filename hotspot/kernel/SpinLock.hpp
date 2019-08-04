//
//  SpinLock.hpp
//  hotspot
//
//  Created by GuanZF on 2019/7/17.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef SpinLock_hpp
#define SpinLock_hpp

#include <stdio.h>

class SpinLock {
public:
    void run();
    static void run_test()
    {
        printf("run test\n");
    }
};

class Base {
public:
    virtual void run()
    {
        printf("base\n");
    }
};

class BaseT1: public Base {
public:
    void run()
    {
        printf("base t1\n");
    }
};

class BaseT2: public Base {
public:
    void run()
    {
        printf("base t2\n");
    }
};

#endif /* SpinLock_hpp */
