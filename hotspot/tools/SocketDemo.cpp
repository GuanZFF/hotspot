//
//  SocketDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "SocketDemo.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/uio.h>

// open函数运行
#include <sys/stat.h>
#include <fcntl.h>

void socket_server() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8888);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(fd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr_in));
    
    listen(fd, 128);
    printf("listen client port = %d... \n", 8888);
    
    struct sockaddr_in client_addr;
    char cli_ip[INET_ADDRSTRLEN] = "";
    socklen_t cliaddr_len = sizeof(client_addr);
    int connfd = 0;
    
    connfd = accept(fd, (struct sockaddr *)&client_addr, &cliaddr_len);
    inet_ntop(AF_INET, &client_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);
    printf("------------------------------------------\n");
    printf("client ip = %s, port = %d\n", cli_ip, ntohs(client_addr.sin_port));
    char recv_buf[512] = "";
    
    long k = 1;
    while(k > 0) {
        k = read(connfd, recv_buf, sizeof(recv_buf));
        printf("recv data = %ld\n", k);
        printf("%s\n", recv_buf);
    }
    
    close(connfd);
    printf("client closed!\n");
    close(fd);
}

void SocketServer::run() {
    printf("socket server run\n");
    socket_server();
}

void SocketClient::run() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(8888);
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int con = connect(fd, (const struct sockaddr *) &client_addr, sizeof(struct sockaddr_in));
    if (con != 0) {
        printf("socket connect fail\n");
    }
    
    printf("socket client success\n");
    
    char message[512];
    long k = 1;
    while (k > 0) {
        scanf("%s", message);
        
        k = write(fd, message, sizeof(message));
    }
    
    printf("socket close\n");
    
    close(fd);
}


void SocketClient::redis_client()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in client_addr;
    
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(6379);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    int cnt = connect(fd, (const struct sockaddr *) &client_addr, sizeof(client_addr));
    if (cnt != 0) {
        printf("connect fail\n");
        close(fd);
        return;
    }
    
    printf("connect success\n");
    
    char message[512] = "";
    char read_message[512] = "";
    long k = 1;
    long r_len = 0;
    while (k > 0) {
        scanf("%s", message);
        
        k = write(fd, message, strlen(message));
        
        r_len = read(fd, read_message, sizeof(read_message));
        if (r_len > 0) {
            printf("%s", read_message);
        }
    }
    
    close(fd);
}

void SocketClient::run_mmap()
{
    
}

void SocketClient::run_sendfile()
{
    int fd = open("/Users/Grow-Worm/Downloads/project/test.txt", O_RDWR);
    
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    long long len = 10;
    
    int sf = sendfile(fd, socket_fd, 0, &len, NULL, 0);
}
