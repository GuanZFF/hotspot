//
//  EpollDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "EpollDemo.hpp"
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// 基于kqueue实现，Linux可以使用epoll实现
//
// kqueue函数
//      kq：kqueue的文件描述符,
//      changelist：注册／反注册的事件数组,
//      nchanges：changelist的元素个数,
//      eventlist：满足条件的通知事件数组,
//      nevents：eventlist的元素个数,
//      timeout：等待事件到来时的超时时间
// kevent函数
//      kevent：事件
//      a：文件描述符
//      b：监控的事件
//      c：事件行为
void EpollServer::run()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(fd, (const struct sockaddr *) &server_addr, sizeof(struct sockaddr_in));
    
    listen(fd, 128);
    
    printf("wait client connect ...\n");
    
    int kq = kqueue();
    
    struct kevent changes;
    EV_SET(&changes, fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    // 注册事件
    kevent(kq, &changes, 1, NULL, 0, NULL);
    
    struct kevent eventlist[10];
    
    while (1) {
        // 阻塞， 判断是否有事件触发
        int event_count = kevent(kq, NULL, 0, eventlist, 10, NULL);
        if (event_count <= 0) {
            continue;
        }
        
        printf("event enable eventCount = %d\n", event_count);
        
        for (int i = 0; i < event_count; i++) {
            struct kevent event = eventlist[i];
            
            // 添加事件
            if (event.ident == fd) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(fd, (struct sockaddr *) &client_addr, &client_addr_len);
                
                char client_ip[INET_ADDRSTRLEN] = "";
                inet_ntop(AF_INET, (const void *) &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
                printf("client ip = %s, port = %d\n", client_ip, ntohl(client_addr.sin_port));
                
                struct kevent connect_event;
                EV_SET(&connect_event, client_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
                
                kevent(kq, &connect_event, 1, NULL, 0, NULL);
                
                continue;
            }
            
            // 读数据
            if (event.filter == EVFILT_READ) {
                char message[512] = "";
                
                int message_len = (int) read((int) event.ident, message, sizeof(message));
                if (message_len <= 0) {
                    printf("delete event fd = %d\n", (int) event.ident);
                    
                    EV_SET(&event, event.ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
                    
                    kevent(kq, &event, 1, NULL, 0, NULL);
                    continue;
                }
                
                printf("message = %s\n", message);
            }
        }
    }
}
