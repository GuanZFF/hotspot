//
//  EpollDemo.hpp
//  hotspot
//
//  Created by GuanZF on 2019/5/9.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#ifndef EpollDemo_hpp
#define EpollDemo_hpp

#include <stdio.h>

class EpollServer {
public:
    void run();
    int add(int a, int b);
};

#endif /* EpollDemo_hpp */
