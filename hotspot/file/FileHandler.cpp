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
// 零拷贝
#include <sys/mman.h>
#include <sys/uio.h>

// open函数运行
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

// 错误处理
#include <errno.h>

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

void FileHandler::run_read()
{
    int fd = open("/Users/Grow-Worm/Downloads/project/test.txt", O_RDWR);
    
    char *buf = (char *) malloc(sizeof(char) * 20);
    
    long r_len = read(fd, buf, sizeof(char) * 20);
    if (r_len <= 0) {
        printf("read fail, fail code = %d\n", errno);
        printf("fail reason : %s\n", strerror(errno));
        free(buf);
        close(fd);
        return;
    }
    
    printf("read success\n");
    
    printf("result = %s\n", buf);
    
    free(buf);
    close(fd);
    
    return;
}

// mmap实现了内核数据向用户数据copy的过程，以一个共享的内存实现
void FileHandler::run_mmap()
{
    int fd = open("/Users/Grow-Worm/Downloads/project/test.txt", O_RDONLY);
    
    // prot :  whether read, write, execute, or some combination of accesses are permitted to the data being mapped
    // flags : provides other information about the handling of the mapped data.
    char *ptr = (char *) mmap(NULL, 20, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == nullptr) {
        printf("mmap read fail.\n");
        return;
    }
    
    printf("result = %s\n", ptr);
    printf("read len = %lu\n", strlen(ptr));
    
    close(fd);
    
    return;
}

void FileHandler::run_sendfile()
{
    
}
