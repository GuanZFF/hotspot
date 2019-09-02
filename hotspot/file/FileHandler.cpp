//
//  FIleHandler.cpp
//  hotspot
//
//  Created by GuanZF on 2019/8/31.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "FileHandler.hpp"
#include "../memory/BaseMemoryAllocate.hpp"
#include <stdlib.h>
#include <string.h>

// fopen mode配置模式
//      r 读模式
//      w 写模式
//      a 追加写
//      + 同时支持读写
void FileHandler::run()
{
    FILE *f = fopen("/Users/Grow-Worm/Downloads/project/test.txt", "a");
    
    char *ptr = (char *) malloc(10 * sizeof(char));
    
    memset(ptr, 0, 10 * sizeof(char));
    
    strcpy(ptr, "1234567890");
    
    long fr = fwrite(ptr, sizeof(char), 10, f);
//    long fr = fread(ptr, sizeof(char), 10, f);
    if (fr <= 0) {
        printf("fail\n");
        fclose(f);
        return;
    }
    
    printf("success\n");
    
    printf("%s\n", ptr);
    
    free(ptr);
    fclose(f);
}
