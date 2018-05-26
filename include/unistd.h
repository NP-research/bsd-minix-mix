#ifndef _UNISTD_H
#define _UNISTD_H

#ifndef _TYPES_H
#include <sys/types.h>
#endif

/* POSIX Table 2-8 start */
#define F_OK            0 /* 测试文件是否存在 */
#define X_OK            1 /* 测试文件是否有执行权限 */
#define W_OK            2 /* 测试文件是否可写 */
#define R_OK            4 /* 测试文件是否可读 */
/* POSIX Table 2-8 end */

/* POSIX Table 2-9: 偏移位置 start */
#define SEEK_SET        0 /* 绝对定位 */
#define SEEK_CUR        1 /* 相对于当前位置偏移 */
#define SEEK_END        2 /* 偏移量相对于文件尾 */
/* POSIX Table 2-9: 偏移位置 end */

/* POSIX Table 2-10 start */
#define _POSIX_VERSION  199009L
/* POSIX Table 2-10 end */

/* POSIX Sec. 8.2.1.2 start */
#define STDIN_FILENO    0 /* stdin */
#define STDOUT_FILENO   1 /* stdout */
#define STDERR_FILENO   2 /* stderr */
/* POSIX Sec. 8.2.1.2 end */

/* 如何退出系统或者如何停止一个服务进程 start */
#ifdef _MINIX
#define RBT_HALT        0
#define RBT_REBOOT      1
#define RBT_PANIC       2
#define RBT_MONITOR     3
#define RBT_RESET       4 /* 系统硬复位 */
#endif //_MINIX
/* 如何退出系统或者如何停止一个服务进程 end */


#endif