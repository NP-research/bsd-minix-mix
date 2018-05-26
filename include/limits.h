#ifndef _LIMITS_H
#define _LIMITS_H

/* char类型定义(8位) start */
#define CHAR_BIT            8   /* char类型位数大小 */
#define CHAR_MIN         (-128)   /* char类型最小取值 */
#define CHAR_MAX          127   /* char类型最大取值 */
#define SCHAR_MIN        (-128)   /* signed char类型最小取值 */
#define SCHAR_MAX         127   /* signed char类型最大取值 */
#define UCHAR_MAX         255   /* unsigned char类型最大取值 */
#define MB_LEN_MAX          1   /* 多字节char类型最大长度 */
/* char类型定义(8位) end */

/* short类型定义(16位) start */
#define SHRT_MIN    (-32767-1)  /* 最小取值 */
#define SHRT_MAX         32767  /* 最大取值 */
#define USHRT_MAX       0xFFFF  /* 无符号最大取值 */
/* short类型定义(16位) end */

/* _EM_WSIZE int类型定义(32位) start */
#define INT_MIN (-2147483647-1)
#define INT_MAX   2147483647
#define UINT_MAX  0xFFFFFFFF
/* _EM_WSIZE int类型定义(32位) end */

/* long类型定义(32位) start */
#define LONG_MIN (-2147483647L-1)
#define LONG_MAX   2147483647L
#define ULONG_MAX  0xFFFFFFFFL
/* long类型定义(32位) end */

#include <sys/dir.h>
/* POSIX下P1003.1(Table 2-3)标准最小必须取值 start */
#ifdef _POSIX_SOURCE
#define _POSIX_ARG_MAX      4096    /* exec调用可传多大内存的参数 */
#define _POSIX_CHILD_MAX       6    /* 一个进程最多有多少个子进程 */
#define _POSIX_LINK_MAX        8    /* 一个文件最多有8个链接 */
#define _POSIX_MAX_CANON     255    /* 输入队列的大小 */
#define _POSIX_MAX_INPUT     255    /* 你可以输入多少字节 */
#define _POSIX_NAME_MAX   DIRSIZ    /* 一个文件名最大长度 */
#define _POSIX_NGROUPS_MAX     0    /* 补充组ID为可选 */
#define _POSIX_OPEN_MAX        16   /* 一个进程最大可同时打开多少文件 */
#define _POSIX_PATH_MAX       255   /* 路径名长度控制 */
#define _POSIX_PIPE_BUF       512   /* 管道写缓冲区, 达到及必须发送 */
#define _POSIX_STREAM_MAX       8   /* 最少可同时打开文件数 */
#define _POSIX_TZNAME_MAX       3   /* 地区名占用 */
#define _POSIX_SSIZE_MAX    32767   /* read调用必须支持大小 */
/* tables2-4, 2-5, 2-6, 2-7 */
#define _NO_LIMIT             100   /*  */
#define NGROUPS_MAX             0   /* 支持组ID无效 */
#define ARG_MAX             16384   /* exec中 args + env 最大大小  */
#define CHILD_MAX       _NO_LIMIT   /* 不限制子进程数量 */
#define OPEN_MAX               20   /* 文件打开数量 */
#define LINK_MAX         SHRT_MAX   /* 链接数量 */
#define MAX_CANON             255
#define MAX_INPUT             255
#define NAME_MAX           DIRSIZ
#define PATH_MAX              255
#define PIPE_BUF             7168
#define STREAM_MAX             20
#define TZNAME_MAX              3
#define SSIZE_MAX           32767
#endif//_POSIX_SOURCE
/* POSIX下P1003.1(Table 2-3)标准最小必须取值 end */

#endif
