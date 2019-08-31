//
//  BaseMemoryAllocte.hpp
//  hotspot
//
//  Created by GuanZF on 2019/8/30.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef BaseMemoryAllocate_hpp
#define BaseMemoryAllocate_hpp

#include <stdio.h>

class MemoryAllocate {
public:
    static void run();
    static void print_memory_space(void *point, int size, int count);
};

#endif /* BaseMemoryAllocte_hpp */
