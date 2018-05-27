#ifndef _FCNTL_H
#define _FCNTL_H

#ifndef _TYPES_H
#include <sys/types.h>
#endif

/* POSIX Talbe 6-1. start */
#define F_DUPFD                 0 /* 复制文件描述符 */
#define F_GETFD                 1 /* 获取/设置文件描述符标志位 */
#define F_SETFD                 2
#define F_GETFL                 3 /* 获取/设置文件描述符状态标志 */
#define F_SETFL                 4
#define F_GETLK                 5 /* 获取/设置锁信息 */
#define F_SETLK                 6
#define F_SETLKW                7 /* 设置锁信息,如果阻塞, 等待 */
/* POSIX Talbe 6-1. end */

/* POSIX Table 6-2. start */
#define FD_CLOEXEC              1 /* 关闭fcntl的第三个参数的exec标志 */
/* POSIX Table 6-2. end */

/* record locking with fcntl(): POSIX Table 6-3. start */
#define F_RDLCK                 1 /* 共享锁或者读锁 */
#define F_WRLCK                 2 /* 独占或者写锁 */
#define F_UNLCK                 3 /* unlock */
/* record locking with fcntl(): POSIX Table 6-3. end */

/* Dflag values for open(): POSIX Table 6-4. start */
#define O_CREAT             00100 /* 文件不存在则创建 */
#define O_EXEC              00200 /* 独占标志 */
#define O_NOCTTY            00400 /* 不分配终端 */
#define O_TRUNC             01000 /* 截断标志 */
/* Dflag values for open(): POSIX Table 6-4. end */

/* 文件状态标志 open and fcntl: POSIX Table 6-5 start */
#define O_APPEND            02000 /* 设置append模式 */
#define O_NONBLOCK          04000 /* 无延迟 */
/* 文件状态标志 open and fcntl: POSIX Table 6-5 end */

/* 文件访问模式 open and fcntl. POSIX Table 6-6 start */
#define O_RDONLY                0 /* read only */
#define O_WRONLY                1 /* write only */
#define O_RDWR                  2 /* read/write */
/* 文件访问模式 open and fcntl. POSIX Table 6-6 end */

/* 文件访问掩码. POSIX Table 6-7 start */
#define O_ACCMODE              03
/* 文件访问掩码. POSIX Table 6-7 end */

/* 用于锁的结构体. POSIX Table 6-8 start */
struct flock {
    short l_type;
    short l_whence; /* 启始偏移 */
    off_t l_start; /* 相对偏移 */
    off_t l_len; /* 大小，如果是0, 直到文件结尾 */
    pid_t l_pid; /* 锁拥有者的进程ID */
};
/* 用于锁的结构体. POSIX Table 6-8 end */

/* function prototypes. start */
_PROTOTYPE( int creat, (const char *_path, _mnx_Mode_t _mode)       );
_PROTOTYPE( int fcntl, (int _filedes, int _cmd, ...)                );
_PROTOTYPE( int open, (const char *_path, int _oflag, ...)          );
/* function prototypes. end */

#endif //_FCNTL_H