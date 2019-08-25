//
//  PollDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/8/24.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "PollDemo.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <poll.h>

void Poll::run()
{
    // 创建socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        printf("socket create fail\n");
        return;
    }
    
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8888);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    // 绑定端口
    bind(fd, (struct sockaddr *) &my_addr, sizeof(struct sockaddr_in));

    // 监听socket
    listen(fd, 128);
    
    printf("Waiting for a connection to be accepted...\n");
    
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // 接受连接
    int client_fd = accept(fd, (struct sockaddr *) &client_addr, &client_addr_len);
    printf("accept success \n");
    if (client_fd < 0) {
        printf("accept connection fail\n");
        return;
    }
    
    char client_ip[INET_ADDRSTRLEN] = "";
    
    inet_ntop(AF_INET, (const void *) &client_addr.sin_addr, (char *) client_ip, INET_ADDRSTRLEN);
    int client_port = ntohs(client_addr.sin_port);
    
    printf("client connect ip = %s, port = %d\n", client_ip, client_port);
    
    // 打印客户端发来的消息
    char message[512] = "";
    
    long k = 1;
    while (k > 0) {
        k = read(client_fd, message, sizeof(message));
        printf("message = %s\n", message);
    }
    
    close(client_fd);
    close(fd);
}


void Poll::run_poll()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        printf("socket creation fail\n");
        return;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(fd, (const struct sockaddr *) &server_addr, sizeof(struct sockaddr_in));
    
    listen(fd, 128);
    
    struct pollfd pfd[10];
    pfd[0].fd = fd;
    pfd[0].events = POLLIN;
    
    printf("wait connect client ...\n");
    
    while (1) {
        int poll_event_count = poll(pfd, (int) (sizeof(pfd) / sizeof(pollfd)), 10000);
        if (poll_event_count == 0) {
            continue;
        }
        if (poll_event_count < 0) {
            printf("poll error\n");
            break;
        }
        
        // 监听到连接事件
        if (pfd[0].revents & POLLIN) {
            int client_index = -1;
            for (int k = 0; k < (int) (sizeof(pfd) / sizeof(pollfd)); k++) {
                if (pfd[k].fd < 0) {
                    client_index = k;
                    break;
                }
            }
            
            printf("connect fd = %d\n", client_index);
            
            if (client_index > 0) {
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int client_fd = accept(pfd[0].fd, (struct sockaddr *) &client_addr, &client_addr_len);
                
                char client_ip[INET_ADDRSTRLEN] = "";
                
                inet_ntop(AF_INET, (const void *) &client_addr.sin_addr, (char *) client_ip, INET_ADDRSTRLEN);
                int client_port = ntohs(client_addr.sin_port);
                
                printf("client connect ip = %s, port = %d\n", client_ip, client_port);
                
                pfd[client_index].fd = client_fd;
                pfd[client_index].events = POLLIN;
            }
        }
        
        //读数据
        for (int i = 1; i < (int) (sizeof(pfd) / sizeof(pollfd)); i++) {
            if (pfd[i].fd < 0) {
                continue;
            }
            
            // 监听到读事件
            if (pfd[i].revents & POLLIN) {
                char message[512] = "";
                int read_len = (int) read(pfd[i].fd, message, sizeof(message));
                
                // 关闭退出的连接
                if (read_len <= 0) {
                    printf("close fd = %d\n", pfd[i].fd);
                    close(pfd[i].fd);
                    pfd[i].fd = -1;
                    break;
                }
                printf("message = %s\n", message);
            }
            
            // 监听到写事件
            if (pfd[i].revents & POLLOUT) {
                char message[512] = "I received your message";
                write(pfd[i].fd, message, sizeof(message));
            }
        }
    }
    
    close(fd);
    
}
