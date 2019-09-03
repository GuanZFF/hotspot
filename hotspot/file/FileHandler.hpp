//
//  FIleHandler.hpp
//  hotspot
//
//  Created by GuanZF on 2019/8/31.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <stdio.h>

class FileHandler {
public:
    static void run();
    // 原始函数操作
    static void run_read();
    
    static void run_mmap();
    
    static void run_sendfile();
};


#endif /* FIleHandler_hpp */
