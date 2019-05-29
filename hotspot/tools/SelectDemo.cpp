//
//  SelectDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "SelectDemo.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/uio.h>

struct client {
    int fd = 0;
    int port = 0;
};

void SelectSocketServer::run() {
    // 启动socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // 绑定端口
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(8888);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(fd, (struct sockaddr *)&my_addr, sizeof(sockaddr));
    
    // 监听
    listen(fd, 128);
    
    // 初始化
    fd_set read_set, total_set;
    FD_ZERO(&read_set);
    FD_SET(fd, &total_set);
    int read_fd_index = 0, max_fd = fd;
    struct client read_fds[10];
    
    while (read_fd_index < 4) {
        read_set = total_set;
        select(max_fd + 1, &read_set, NULL, NULL, NULL);
        
        // 监听句柄判断
        if (FD_ISSET(fd, &read_set)) {
            // 接收客户端连接
            struct sockaddr_in client_addr;
            socklen_t len = sizeof(client_addr);
            int cli_fd = accept(fd, (struct sockaddr *)&client_addr, &len);
            read_fds[read_fd_index].fd = cli_fd;
            read_fds[read_fd_index++].port = ntohs(client_addr.sin_port);
            FD_SET(cli_fd, &total_set);
            max_fd = cli_fd;
            
            // 打印连接信息
            char cli_ip[INET_ADDRSTRLEN] = "";
            inet_ntop(AF_INET, &client_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);
            printf("%s %d\n", cli_ip, ntohs(client_addr.sin_port));
        }
        
        // 读句柄判断
        for (int i = 0; i < 10; i++) {
            int read_fd = read_fds[i].fd;
            if (read_fd > 0 && FD_ISSET(read_fd, &read_set)) {
                char recv_buf[512] = "";
                ssize_t rs = read(read_fd, recv_buf, sizeof(recv_buf));
                if(rs == 0) {
                    close(read_fd);
                    FD_CLR(read_fd, &total_set);
                }else{
                    printf("port = %d, data = %s\n", read_fds[i].port, recv_buf);
                }
            }
        }
    }
    
    // 关闭连接信息
    close(fd);
}
