//
//  ThreadDemo.cpp
//  hotspot
//
//  Created by GuanZF on 2019/7/4.
//  Copyright © 2019 gzfeng. All rights reserved.
//

#include "ThreadDemo.hpp"
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void * test_th1(void *t) {
    
    int *arg = (int *)t;
    
    cout << "这是一个子线程1, arg = " << *arg << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << "线程执行1" << i << endl;
        sleep(1);
    }
    
    return NULL;
}

void * test_th2(void *t) {
    
    int *arg = (int *)t;
    
    cout << "这是一个子线程2, arg = " << *arg << endl;
    
    for (int i = 0; i < 10; i++) {
        cout << "线程执行2" << i << endl;
        sleep(1);
    }
    
    return NULL;
}

void ThreadDemo::run() {
    
    int arg = 10;
    
    pthread_t th1;
    
    int p = pthread_create(&th1, NULL, test_th1, &arg);
    if (p != 0) {
        cout << "thread1 create fail." << endl;
    }
    
    cout << "thread1 successful." << endl;
    
    pthread_t th2;
    
    int p2 = pthread_create(&th2, NULL, test_th2, &arg);
    if (p2 != 0) {
        cout << "thread2 create fail." << endl;
    }
    
    cout << "thread2 successful." << endl;
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
}

struct user_struct {
    int age;
    char name[56];
};

typedef struct user_struct other_user_struct;

typedef other_user_struct anothre_user_struct;

// 加锁函数
void *lock_mutex(void *lock) {
    
    pthread_mutex_t *t = (pthread_mutex_t *)lock;
    
    int p = pthread_mutex_lock(t);
    if (p == 0) {
        cout << "加锁成功" << endl;
    } else {
        cout << "加锁失败" << endl;
    }
    
    cout << pthread_self() << endl;
    
    sleep(3);
    
    int unlock = pthread_mutex_unlock(t);
    if (unlock == 0) {
        cout << "解锁成功" << endl;
    } else {
        cout << "解锁失败" << endl;
    }

    return NULL;
}

void ThreadDemo::lock_test()
{
    // Linux锁原理
    
    cout << this->thread_count << endl;
    
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    
    pthread_t t1;
    
    int p1 = pthread_create(&t1, NULL, lock_mutex, &lock);
    if (p1 == 0) {
        cout << "线程1创建成功" << endl;
    }
    
    pthread_t t2;
    
    int p2 = pthread_create(&t2, NULL, lock_mutex, &lock);
    if (p2 == 0) {
        cout << "线程2创建成功" << endl;
    }
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

void ThreadDemo::lock_cond_test()
{
    cout << "LOCK_COND_TEST" << endl;
    
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    
    int cond_v = pthread_cond_wait(&cond, &mutex);
}

int ThreadDemo::get_thread_count()
{
    return this->thread_count;
}

void ThreadDemo::set_thread_count(int count)
{
    this->thread_count = count;
}

typedef int jint;

typedef enum num {
    one = 1,
    two = 2,
    three = 3,
} n;

void ThreadDemo::print_thread()
{
    volatile n o = one;
    cout << o << endl;
}
