//
//  JvmDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/7/13.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef JvmDemo_hpp
#define JvmDemo_hpp

#include <iostream>

using namespace std;

class JvmDemo {
public:
    void run();
    static void run_test(string context);
    
    static void jvm_print(const char *context);
    
    static void enum_test();
    
    
//    static int _call_stub_entry;
};

#endif /* JvmDemo_hpp */
