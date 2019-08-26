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
