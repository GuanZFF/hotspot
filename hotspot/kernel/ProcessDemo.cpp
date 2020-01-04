//
//  ProcessDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2020/1/4.
//  Copyright © 2020 gzfeng. All rights reserved.
//

#include "ProcessDemo.hpp"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

extern int errno;

void ProcessDemo::msg_send()
{
    int msgId = msgget(IPC_PRIVATE, IPC_CREAT);
    if (msgId <= 0) {
        printf("消息创建失败\n");
        return;
    }
    
    struct mymsg buf;
    
    buf.mtype = 1 ;
    strcpy(buf.mtext, "happy new year!") ;
    
    int sendLength;
    
    sendLength = sizeof(struct mymsg) - sizeof(long);
    
    int msgSndId = msgsnd(msgId, &buf, sendLength, 0);
    if (msgSndId != 0) {
        printf("消息发送失败%d\n", errno);
        return;
    }
    
    printf("test process \n");
}

void ProcessDemo::msg_rec()
{
    printf("test process \n");
}
