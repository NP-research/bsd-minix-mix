#ifndef _ERRNO_H
#define _ERRNO_H

/* 根据_SYSTEM宏定义_SIGN为""或者 "-" start */
#ifdef _SYSTEM
#   define _SIGN        -
#   define OK           0
#else
#   define _SIGN
#endif
/* 根据_SYSTEM宏定义_SIGN为""或者 "-" end */

extern int errno;

/* 错误码定义 start */
#define _NERROR                 70  /* 错误数量 */
#define EGENERIC        (_SIGN 99)  /* 一般性错误 */
#define EPERM           (_SIGN  1)  /* 不允许的操作 */
#define ENOENT          (_SIGN  2)  /* 文件或目录不存在 */
#define ESRCH           (_SIGN  3)  /* 进程不存在 */
#define EINTR           (_SIGN  4)  /* 中断函数调用 */
#define EIO             (_SIGN  5)  /* i/o 错误 */
#define ENXIO           (_SIGN  6)  /* 设备地址不存在 */
#define E2BIG           (_SIGN  7)  /* 参数列表过长(超出include/limits.h中的ARG_MAX设置大小) */
#define ENOEXEC         (_SIGN  8)  /* exec调用格式错误 */
#define EBADF           (_SIGN  9)  /* 文件描述符错误 */
#define ECHILD          (_SIGN 10)  /* 没有子进程 */
#define EAGAIN          (_SIGN 11)  /* 资源临时无效 */
#define ENOMEM          (_SIGN 12)  /* 没有足够的空间 */
#define EACCES          (_SIGN 13)  /* 没有权限拒绝访问 */
#define EFAULT          (_SIGN 14)  /* 地址错误 */
#define ENOTBLK         (_SIGN 15)  /* 不是一个特殊文件 */
#define EBUSY           (_SIGN 16)  /* 资源忙碌 */
#define EEXIST          (_SIGN 17)  /* 文件存在 */
#define EXDEV           (_SIGN 18)  /* 链接不正确 */
#define ENODEV          (_SIGN 19)  /* 设备不存在 */
#define ENOTDIR         (_SIGN 20)  /* 不是一个目录 */
#define EISDIR          (_SIGN 21)  /* 是一个目录 */
#define EINVAL          (_SIGN 22)  /* 参数不正确 */
#define ENFILE          (_SIGN 23)  /* 系统中打开文件过多 */
#define EMFILE          (_SIGN 24)  /* 过多打开文件 */
#define ENOTTY          (_SIGN 25)  /* 不恰当的I/O控制操作 */
#define ETXTBSY         (_SIGN 26)  /* 长时间未使用 */
#define EFBIG           (_SIGN 27)  /* 文件过大 */
#define ENOSPC          (_SIGN 28)  /* 设备没有剩余空间 */
#define ESPIPE          (_SIGN 29)  /* 无效的偏移 */
#define EROFS           (_SIGN 30)  /* 只读文件系统 */
#define EMLINK          (_SIGN 31)  /* 过多的链接数 */
#define EPIPE           (_SIGN 32)  /* broken pipe */
#define EDOM            (_SIGN 33)  /* 域错误 (标准C定义) */
#define ERANGE          (_SIGN 34)  /* 结果过长(标准C定义) */
#define EDEADLK         (_SIGN 35)  /* 资源死锁避免 */
#define ENAMETOOLONG    (_SIGN 36)  /* 文件名过长 */
#define ENOLCK          (_SIGN 37)  /* 没有锁 */
#define ENOSYS          (_SIGN 38)  /* 函数未应用 */
#define ENOTEMPTY       (_SIGN 39)  /* 目录不为空 */

//以下错误码应用于network
#define EPACKSIZE       (_SIGN 50)  /* 某些协议的数据包大小无效 */
#define EOUTOFBUFS      (_SIGN 51)  /* 没有足够的缓冲 */
#define EBADIOCTL       (_SIGN 52)  /* 非法ioctl设备 */
#define EBADMODE        (_SIGN 53)  /* ioctl错误模式 */
#define EWOULDBLOCK     (_SIGN 54)
#define EBADDEST        (_SIGN 55)  /* 非有效源地址 */
#define EDSTNOTRCH      (_SIGN 56)  /* 目标地址不可达 */
#define EISCONN         (_SIGN 57)  /* 都准备好了 */
#define EADDRINUSE      (_SIGN 58)  /* 地址已被使用 */
#define ECONNREFUSED    (_SIGN 59)  /* 连接重用 */
#define ECONNRESET      (_SIGN 60)  /* 连接重置 */
#define ETIMEDOUT       (_SIGN 61)  /* 连接超时 */
#define EURG            (_SIGN 62)  /* 紧急数据 */
#define ENOURG          (_SIGN 63)  /* 无紧急数据 */
#define ENOTCONN        (_SIGN 64)  /* 无连接 */
#define ESHUTDOWN       (_SIGN 65)  /* 关闭连接的写 */
#define ENOCONN         (_SIGN 66)  /* 没有这样的连接 */
#define EAFNOSUPPORT    (_SIGN 67)  /* 地址蔟不支持 */
#define EPROTONOSUPPORT (_SIGN 68)  /* 协议不支持AF */
#define EPROTOTYPE      (_SIGN 69)  /* socket错误类型 */
#define EINPROGRESS     (_SIGN 70)  /* 操作进展 */
#define EADDRNOTAVAIL   (_SIGN 71)  /* 不能分配请求的地址 */
#define EALREADY        (_SIGN 72)  /* 连接已准备好 */
#define EMSGSIZE        (_SIGN 73)  /* 消息过长 */

//以下不是posix错误，它们都是内核生成的，都与消息传递相关
#define ELOCKED         (_SIGN 101) /* 无法发送，消息死锁 */
#define EBADCALL        (_SIGN 102) /* 非法系统调用号  */
#define EBADSRCDST      (_SIGN 103) /* 错误的来源进程或者目标进程 */
#define ECALLDENIED     (_SIGN 104) /* 系统调用无权限 */
#define EDEADDST        (_SIGN 105) /* 发送目的地不存在 */
#define ENOTREADY       (_SIGN 106) /* 来源或者目标未准备好 */
#define EBADREQUEST     (_SIGN 107) /* 目标无法处理请求 */
#define EDONTREPLY      (_SIGN 201) /* 不要发送回复 */
/* 错误码定义 end */

#endif
