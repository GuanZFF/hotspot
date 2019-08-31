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

void FileHandler::run()
{
    FILE *f = fopen("/Users/Grow-Worm/Downloads/project/test.txt", "wa+");
    
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
