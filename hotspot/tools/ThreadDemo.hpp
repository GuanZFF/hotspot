//
//  ThreadDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/7/4.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef ThreadDemo_hpp
#define ThreadDemo_hpp

#include <stdio.h>

class ThreadDemo {
private:
    int thread_count;
public:
    void run();
    
    void lock_test();
    
    void lock_cond_test();
    
    int get_thread_count();
    
    void set_thread_count(int count);
    
    void print_thread();
};

#endif /* ThreadDemo_hpp */
