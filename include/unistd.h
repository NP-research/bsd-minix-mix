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

/* 检索系统信息 start */
#define SI_KINFO            0 /* 通过PM获取内核信息 */
#define SI_PROC_ADDR        1 /* 进程表的地址 */
#define SI_PROC_TAB         2 /* 过程表的副本 */
#define SI_DMAP_TAB         3 /* 获取社别 <-> 驱动映射 */
/* 检索系统信息 end */

/* NULL必须定义在<unistd.h> POSIX Sec. 2.7.1 */
#define NULL      ((void *)0)

/* 可配置系统变量 POSIX Table 4-2. start */
#define _SC_ARG_MAX         1
#define _SC_CHILD_MAX       2
#define _SC_CLOCKS_PER_SEC  3
#define _SC_CLK_TCK         3
#define _SC_NGROUPS_MAX     4
#define _SC_OPEN_MAX        5
#define _SC_JOB_CONTROL     6
#define _SC_SAVED_IDS       7
#define _SC_VERSION         8
#define _SC_STREAM_MAX      9
#define _SC_TZNAME_MAX     10
/* 可配置系统变量 POSIX Table 4-2. end */

/* 可配置路径名变量 POSIX Table 5-2. start */
#define _PC_LINK_MAX        1 /* 链接总数 */
#define _PC_MAX_CANON       2 /* 规范输入队列的大小 */
#define _PC_MAX_INPUT       3 /* 输入缓冲区大小 */
#define _PC_NAME_MAX        4 /* 文件名大小 */
#define _PC_PATH_MAX        5 /* 路径名大小 */
#define _PC_PIPE_BUF        6 /* 管道大小 */
#define _PC_NO_TRUNC        7 /* 处理长名称组建 */
#define _PC_VDISABLE        8 /* tty disable */
#define _PC_CHOWN_RESTRICTED 9 /* chown 受限制或者不受限制 */
/* 可配置路径名变量 POSIX Table 5-2. end */

/*
 * POSIX定义了几个可能实现或不实现的选项，在这，做了以下选择
 * _POSIX_JOB_CONTROL       no defined:     no job control
 * _POSIX_SAVED_IDS         not defined:    no saved uid/gid
 * _POSIX_NO_TRUNC          defined as -1:  long path names are truncated
 * _POSIX_CHOWN_RESTRICTED  defined:        you can't give away files
 * _POSIX_VDISABLE          defined:        tty functions can be disabled
 * */
#define _PPOSIX_NO_TRUNC        (-1)
#define _POSIX_CHOWN_RESTRICTED    1

/* function prototypes. start */
_PROTOTYPE( void _exit, (int _status)                               );
_PROTOTYPE( int access, (const char *_path, int _amode)             );
_PROTOTYPE( unsigned int alarm, (unsigned int _seconds)             );
_PROTOTYPE( int chdir, (const char *_path)                          );
_PROTOTYPE( int fchdir, (int fd)                                    );
_PROTOTYPE( int chown, (const char *_path, _mnx_Uid_t _owner, _mnx_Gid_t _group) );
_PROTOTYPE( int close, (int _fd)                                    );
_PROTOTYPE( char *ctermid, (char *_s)                               );
_PROTOTYPE( char *cuserid, (char *_s)                               );
_PROTOTYPE( int dup, (int _fd)                                      );
_PROTOTYPE( int dup2, (int _fd, int _fd2)                           );
_PROTOTYPE( int execl, (const char *_path, const char *_arg, ...)   );
_PROTOTYPE( int execle, (const char *_path, const char *_arg, ...)  );
_PROTOTYPE( int execlp, (const char *_file, const char *arg, ...)   );
_PROTOTYPE( int execv, (const char *_path, char *const _argv[])     );
_PROTOTYPE( int execve, (const char *_path, char *const _argv[],
                                                char *const _envp[]));
_PROTOTYPE( int execvp, (const char *_file, char *const _argv[])    );
_PROTOTYPE( pid_t fork, (void)                                      );
_PROTOTYPE( long fpathconf, (int _fd, int _name)                    );
_PROTOTYPE( char *getcwd, (char *_buf, size_t _size)                );
_PROTOTYPE( gid_t getegid, (void)                                   );
_PROTOTYPE( uid_t geteuid, (void)                                   );
_PROTOTYPE( gid_t getgid, (void)                                    );
_PROTOTYPE( int getgroups, (int _gidsetsize, gid_t _grouplist[])    );
_PROTOTYPE( char *getlogin, (void)                                  );
_PROTOTYPE( pid_t getpgrp, (void)                                   );
_PROTOTYPE( pid_t getpid, (void)                                    );
_PROTOTYPE( pid_t getppid, (void)                                   );
_PROTOTYPE( uid_t getuid, (void)                                    );
_PROTOTYPE( int isatty, (int _fd)                                   );
_PROTOTYPE( off_t lseek, (int _fd, off_t _offset, int _whence)      );
_PROTOTYPE( long pathconf, (const char *_path, int _name)           );
_PROTOTYPE( int pause, (void)                                       );
_PROTOTYPE( int pipe, (int _fildes[2])                              );
_PROTOTYPE( ssize_t read, (int _fd, void *_buf, size_t _n)          );
_PROTOTYPE( int rmdir, (const char *_path)                          );
_PROTOTYPE( int setgid, (_mnx_Gid_t _gid)                           );
_PROTOTYPE( int setpgid, (pid_t _pid, pid_t _pgid)                  );
_PROTOTYPE( pid_t setsid, (void)                                    );
_PROTOTYPE( int setuid, (_mnx_Uid_t _uid)                           );
_PROTOTYPE( unsigned int sleep, (unsigned int _seconds)             );
_PROTOTYPE( long sysconf, (int _name)                               );
_PROTOTYPE( pid_t tcgetpgrp, (int _fd)                              );
_PROTOTYPE( int tcsetpgrp, (int _fd)                                );
_PROTOTYPE( char *ttyname, (int _fd)                                );
_PROTOTYPE( int unlink, (const char *_path)                         );
_PROTOTYPE( int unlink, (const char *_path)                         );
_PROTOTYPE( ssize_t write, (int _fd, const void *_burf, size_t _n)  );

/* Open Group Base Specifications Issue 6( not complete ) start */
_PROTOTYPE( int symlink, (const char *path1, const char *path2)     );
_PROTOTYPE( int getopt, (int _argc, char **_argv, char *_opts)      );
extern char *optarg;
extern int optind, opterr, optop;
_PROTOTYPE( int usleep, (useconds_t _useconds)                      );

#ifdef _MINIX
#ifndef _TYPE_H
#include <minix/type.h>
#endif

_PROTOTYPE( int brk, (char *_addr)                                  );
_PROTOTYPE( int chroot, (const char *_name)                         );
_PROTOTYPE( int mknod, (const char *_name, _mnx_Mode_t _mode, Dev_t _addr));
_PROTOTYPE( int mknod4, (const char *_name, _mnx_Mode_t _mode, Dev_t _addr,
                        long _size)                                  );
_PROTOTYPE( int *mktemp, (char *_template)                           );
_PROTOTYPE( int mount, (char *_spec, char *_name, int _flag)         );
_PROTOTYPE( long ptrace, (int _req, pid_t _pid, long _addr， long _data));
_PROTOTYPE( char *sbrk, (int _incr)                                  );
_PROTOTYPE( int sync, (void)                                         );
_PROTOTYPE( int fsync, (int fd)                                      );
_PROTOTYPE( int umount, (const char *_name)                          );
_PROTOTYPE( int reboot, (int _how, ...)                              );
_PROTOTYPE( int gethostname, (char *_hostname, size_t _len)          );
_PROTOTYPE( int getdomainname, (char *_domain, size_t _len)          );
_PROTOTYPE( int ttyslot, (void)                                      );
_PROTOTYPE( int fttyslot, (int _fd)                                  );
_PROTOTYPE( char *crypt, (const char *_key, const char *_salt)       );
_PROTOTYPE( int getsysinfo, (int who, int what, void *where)         );
_PROTOTYPE( int getprocnr, (void)                                    );
_PROTOTYPE( int findproc, (char *proc_name, int *proc_nc)            );
_PROTOTYPE( int allocmem, (phys_bytes size, phys_bytes *base)        );
_PROTOTYPE( int freemem, (phys_bytes size, phys_bytes base)          );
#define DEV_MAP     1
#define DEV_UNMAP   2
#define mapdriver(driver, device, style) devctl(DEV_MAP, driver, device, style)
#define unmapdriver(device) devctl(DEV_UNMAP, 0, device, 0)
_PROTOTYPE( int devctl, (int ctl_req, int driver, int device, int style));

/* 兼容其他unix系统 */
_PROTOTYPE( int getpagesize, (void)                                     );
_PROTOTYPE( int setpagesize, (void)                                     );
#endif //_MINIX

_PROTOTYPE( int readline, (const char *, char *, int));
_PROTOTYPE( int getopt, (int, char **, char *));
extern int optind, opterr, optopt;

/* function prototypes. end */

#endif