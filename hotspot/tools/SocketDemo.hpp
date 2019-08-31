//
//  SocketDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef SocketDemo_hpp
#define SocketDemo_hpp

#include <stdio.h>

// socket服务端
class SocketServer {
public:
    void run();
};

// socket客户端
class SocketClient {
public:
    static void run();
};

#endif /* SocketDemo_hpp */
