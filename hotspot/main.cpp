//
//  main.cpp
//  hotspot 模拟Java虚拟机
//
//  Created by GuanZF on 2019/4/25.
//  Copyright © 2019 gzfeng. All rights reserved.
//
#include <iostream>
#include "tools/EpollDemo.hpp"

using namespace std;

typedef int (*test)(int a, int b);

int add(int a, int b) {
    return a + b;
}

test generate_test() {
    return add;
}

int main(int argc, const char * argv[]) {
    
    cout << "这是测试代码" << endl;
    
    EpollServer *server = new EpollServer();
    server->run();
    
    cout << "计算结果:" << server->add(12, 23) << endl;
    
    cout << "测试程序执行完成" << endl;
    
    cout << generate_test()(11, 11) << endl;
    
    test t = add;
    
    cout << t(12, 23) << endl;
    
    cout << "test1" << endl;
    
    cout << "test2" << endl;
    
    return 0;
}
