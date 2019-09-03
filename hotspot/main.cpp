//
//  main.cpp
//  hotspot 模拟Java虚拟机
//
//  Created by GuanZF on 2019/4/25.
//  Copyright © 2019 gzfeng. All rights reserved.
//
#include <iostream>
#include "jvm/JvmDemo.hpp"
#include "tools/SelectDemo.hpp"
#include "tools/SocketDemo.hpp"
#include "tools/PollDemo.hpp"
#include "tools/EpollDemo.hpp"
#include "memory/BaseMemoryAllocate.hpp"
#include "file/FileHandler.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    FileHandler::run_mmap();
    
    cout << "test2" << endl;
    
    cout << "test3" << endl;
    
    return 0;
}
