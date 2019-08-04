//
//  main.cpp
//  hotspot 模拟Java虚拟机
//
//  Created by GuanZF on 2019/4/25.
//  Copyright © 2019 gzfeng. All rights reserved.
//
#include <iostream>
#include "jvm/JvmDemo.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    JvmDemo *jvm = new JvmDemo();
    jvm->run();
    
    return 0;
}
