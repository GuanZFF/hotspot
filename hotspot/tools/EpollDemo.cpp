//
//  EpollDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "EpollDemo.hpp"
#include <sys/socket.h>
#include <poll.h>

void EpollServer::run() {
    printf("guanzhenfeng\n");
    
}

int EpollServer::add(int a, int b) {
    return a + b;
}
