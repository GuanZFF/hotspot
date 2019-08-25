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
    printf("socket client run\n");
}
