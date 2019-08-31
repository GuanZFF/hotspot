//
//  BaseMemoryAllocte.cpp
//  hotspot
//
//  Created by GuanZF on 2019/8/30.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "BaseMemoryAllocate.hpp"
#include <stdlib.h>
#include <string.h>

void MemoryAllocate::print_memory_space(void *point, int size, int count)
{
    printf("memory data : ");
    char *p = (char *) point;
    
    for (int k = 0; k < count; k++) {
        for (int i = k * size; i < (k + 1) * size; i++) {
            printf("%x", *(p + i));
        }
        printf(" ");
    }
    
    printf("\n");
}

// printf("%p\n", point);打印地址
//
void MemoryAllocate::run()
{
    long *point = (long *) malloc(2 * sizeof(long));
    
    memset(point, 0, 2 * sizeof(long));
    
//    long *point = (long *) calloc(2, sizeof(long));
    printf("%p\n", point);
    
    *point = 12;
//    *(point + 1) = 13;
    
    print_memory_space(point, 8, 2);
    
    long *rpoint = (long *) realloc(point, sizeof(long) * 4);
    printf("%p\n", rpoint);
    
    memset(rpoint, 15, 4 * sizeof(long));
    
    *(rpoint + 2) = 14;
    
    
    print_memory_space(rpoint, 8, 4);
    
    free(rpoint);
}

