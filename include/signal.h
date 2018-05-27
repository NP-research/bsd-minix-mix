#ifndef _SIGNAL_H
#define _SIGNAL_H

#ifndef _ANSI_H
#include <ansi.h>
#endif //_SIGNAL_H

#ifdef _POSIX_SOURCE
#ifndef _TYPES_H
#include <sys/types.h>
#endif //_TYPES_H
#endif //_POSIX_SOURCE

/* 信号处理密切相关的类型 start */
typedef int sig_atomic_t;

#ifdef _POSIX_SOURCE
#ifndef _SIGSET_T
#define _SIGSET_T
typedef unsigned long sigset_t;
#endif //_SIGSET_T
#endif //_POSIX_SOURCE

#define _NSIG               20 /* 使用的信号数量 */

#define SIGHUP               1 /* hangup */
#define SIGINT               2 /* 中断(DEL) */
#define SIGQUIT              3 /* quit (ASCII FS) */
#define SIGILL               4 /* 非法指令 */
#define SIGTRAP              5 /* 陷阱(被捕获时不重置) */
#define SIGABRT              6 /* IOT指令 */
#define SIGUNUSED            7 /* 备用代码 */
#define SIGFPE               8 /* 浮点异常 */
#define SIGKILL              9 /* 杀死(无法捕获或忽略) */
#define SIGUSR1             10 /* user defined signal #1 */
#define SIGSEGV             11 /* 段错误 */
#define SIGUSER2            12 /* user defined signal #2 */
#define SIGPIPE             13 /* write on a pipe with no one to read it */
#define SIGALRM             14 /* alarm clock */
#define SIGTERM             15 /* software termination signal from kill */
#define SIGCHILD            17 /* child process terminated or stopped */
#define SIGEMT               7 /* obsolete */
#define SIGBUS              10 /* obsolete */

/* MINIX 特殊信号, 这些信号无法用于用户程序， 但意在通知系统进程, 如PM和system events*/
#define SIGKMESS            18 /* new kernel message */
#define SIGKSIG             19 /* kernel signal peding */
#define SIGKSTOP            20 /* kernel shutting down */

/* POSIX信号定义 */
#define SIGCONT             18
#define SIGSTOP             19
#define SIGTSTP             20
#define SIGTTIN             21 /* 后台程序试图读 */
#define SIGTTOU             22 /* 后台程序试图写 */

/* 信号处理选项 */
typedef void _PROTOTYPE((*__sighandler_t), (int));
#define SIG_ERR         ((__sighandler_t) -1) /* error return */
#define SIG_DFL         ((__sighandler_t)  0) /* 默认信号处理 */
#define SIG_IGN         ((__sighandler_t)  1) /* 忽略信号 */
#define SIG_HOLD        ((__sighandler_t)  2) /* 阻塞信号 */
#define SIG_CATCH       ((__sighandler_t)  3) /* 捕获信号 */
#define SIG_MESS        ((__sighandler_t)  4) /* 作为消息传递(MINIX) */

#ifdef _POSIX_SOURCE
struct sigaction {
    __sighandler_t sa_handler; /* SIG_DFL, SIG_IGN 或者其他函数指针 */
    sigset_t sa_mask; /* 信号在处理时被阻塞 */
    int sa_flags; /* special flags */
};
/* fields for sa_flags */
#define SA_ONSTACK          0x0001 /* 在备用堆栈上传送信号 */
#define SA_RESETHAND        0x0002 /* 信号捕获时重置处理程序 */
#define SA_NODEFER          0x0004 /* 捕获时不要阻止信号 */
#define SA_RESTART          0x0008 /* 自动重启系统调用 */
#define SA_SIGINFO          0x0010 /* 扩展信号处理 */
#define SA_NOCLDWAIT        0x0020 /* 不要创建僵尸进程 */
#define SA_NOCLDSTOP        0x0040 /* 子进程SIGCHLD时不会接收消息 */

/* sigprocmask */
#define SIG_BLOCK                0 /* 阻塞信号 */
#define SIG_UNBLOCK              1 /* 解除阻塞 */
#define SIG_SETMASK              2 /* 设置signal mask */
#define SIG_INQUIRE              4 /* 仅内部使用 */
#endif //_POSIX_SOURCE

/* POSIX and ANSI function prototypes */
_PROTOTYPE( int raise, (int _sig)                                   );
_PROTOTYPE( __sighandler_t signal, (int _sig, __sighandler_t _func) );
#ifdef _POSIX_SOURCE
_PROTOTYPE( int kill, (pid_t _pid, int _sig)				);
_PROTOTYPE( int sigaction,
    (int _sig, const struct sigaction *_act, struct sigaction *_oact)	);
_PROTOTYPE( int sigaddset, (sigset_t *_set, int _sig)			);
_PROTOTYPE( int sigdelset, (sigset_t *_set, int _sig)			);
_PROTOTYPE( int sigemptyset, (sigset_t *_set)				);
_PROTOTYPE( int sigfillset, (sigset_t *_set)				);
_PROTOTYPE( int sigismember, (const sigset_t *_set, int _sig)		);
_PROTOTYPE( int sigpending, (sigset_t *_set)				);
_PROTOTYPE( int sigprocmask,
	    (int _how, const sigset_t *_set, sigset_t *_oset)		);
_PROTOTYPE( int sigsuspend, (const sigset_t *_sigmask)			);
#endif //_POSIX_SOURCE
/* 信号处理密切相关的类型 end */

#endif //_SIGNAL_H
