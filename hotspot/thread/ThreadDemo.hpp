//
//  ThreadDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/7/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef ThreadDemo_hpp
#define ThreadDemo_hpp

#include <stdio.h>

class ThreadDemo {
    int count;
    
public:
    void setCount(int count);
    int getCount();
    
    void run_test();
};

#endif /* ThreadDemo_hpp */
