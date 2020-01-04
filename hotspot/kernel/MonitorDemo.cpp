//
//  MonitorDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/12/11.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "MonitorDemo.hpp"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std;


void MonitorDemo::test()
{
    cout << "start monitor!!!" << endl;
    
    cpu_load_test();
}

void MonitorDemo::cpu_load_test()
{
    double loadavg[3];
    int nelem = 3;
    int result = getloadavg(loadavg, nelem);
    if (result == -1) {
        cout << "获取load值失败" << endl;
        return;
    }
    
    cout << loadavg[0] << " " << loadavg[1] << " " << loadavg[2] << endl;
}

void MonitorDemo::cpu_ratio_test()
{
    int msgId = msgget(IPC_PRIVATE, IPC_CREAT);
    if (msgId > 0) {
        printf("获取消息队列成功ID = %d\n", msgId);
    } else {
        printf("消息创建失败\n");
    }
}
