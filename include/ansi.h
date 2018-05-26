/**
 * 测试编译器是否符合ANSI C
 * <ansi.h>
 */
#ifndef _ANSI_H
#define _ANSI_H

/* define ANSI功能测试macro start */
#if __STDC__ == 1
#define _ANSI       31459
#endif

#ifdef __GUNC__
#define _ANSI       31459
#endif
/* define ANSI功能测试macro end */

/* 兼容ANSI和K&R语法 start */
#ifdef _ANSI
//ANSI
//_PROTOTYPE(return-type function-name, (argument-type argument, ...))
#define _PROTOTYPE(function, params)    function params
#define _ARGS(params)                   params
#define _VOIDSTAR   void *
#define _VOID       void
#define _CONST      const
#define _VOLATILE   volatile
#define _SIZET      size_t

#else
//K&R
#define _PROTOTYPE(function, params)    function()
#define _ARGS(params)                   ()
#define _VOIDSTAR           void *
#define _VOID               void
#define _CONST
#define _VOLATILE
#define _SIZET      int
#endif
/* 兼容ANSI和K&R语法 end */


/* C99编译器 start */
#define _RESTRICT
#if defined(_MINIX) || _POSIX_C_SOURCE > 0 || defined(_POSIX2_SOURCE)
#undef _POSIX_SOURCE
#define _POSIX_SOURCE   1
#endif
/* C99编译器 end */

#endif //_ANSI_H