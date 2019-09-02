## hotspot原理解析

C++项目demo

### select原理

int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);

void FD_SET(fd, fd_set *fdset); 设置要监控的文件描述符

### poll原理

int poll(struct pollfd fds[], nfds_t nfds, int timeout);

struct pollfd {
        int    fd;       /* file descriptor */
        short  events;   /* events to look for */
        short  revents;  /* events returned */
};

### kqueue原理

int kevent(int kq, const struct kevent *changelist, int nchanges, struct kevent *eventlist, int nevents, const struct timespec *timeout);

int kqueue(void);

EV_SET(&kev, ident, filter, flags, fflags, data, udata);

### pthread Linux中的多线程

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);

### FILE文件操作

FILE *fopen(const char * restrict path, const char * restrict mode); // 打开文件返回一个文件句柄
1. path 文件路径
2. mode操作模式
    1. 'r' 读文件
    2. ‘w' 写文件
    3. ’a' 追加写文件
    4. ‘+’ following 'r', 'w', or 'a' opens the file for both reading and writing
    
size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
