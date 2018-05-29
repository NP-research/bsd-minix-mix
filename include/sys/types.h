#ifndef _TYPES_H
#define _TYPES_H

#ifndef _ANSI_H
#include <ansi.h>
#endif //_ANSI_H

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int size_t;
#endif //_SIZE_T

#ifndef _SSIZE_T
#define _SSIZE_T
typedef int ssize_t;
#endif //_SSIZE_T

#ifndef _TIME_T
#define _TIME_T
typedef long time_t; /* GMT 1970 1.1 */
#endif //_TIME_T

#ifndef _CLOCK_T
#define _CLOCK_T
typedef long clock_t;
#endif //_CLOCK_T

#ifndef _SIGSET_T
#define _SIGSET_T
typedef unsigned long sigset_t;
#endif //_SIGSET_T

typedef long useconds_t; /* 微秒 */

/* 磁盘，inode等数据结构中使用的类型 start */
typedef short            dev_t; //holds (major minor) device pair
typedef char             gid_t; //group id
typedef unsigned long    ino_t;  //i-node number (V3 filesystem)
typedef unsigned short  mode_t; //file type and permissions bits
typedef short          nlink_t; //number of links to a file
typedef unsigned long    off_t; //offset within a file
typedef int              pid_t; //process id (must be signed)
typedef short            uid_t; //user id
typedef unsigned long   zone_t; //zone number
typedef unsigned long  block_t; //block number
typedef unsigned long    bit_t; //bit number in a bit map
typedef unsigned short zone1_t; //zone number for V1 file systems
typedef unsigned short bitchunk_t; //collection of bits in a bitmap

typedef unsigned char      u8_t; //8 bit type
typedef unsigned short    u16_t; //16 bit type
typedef unsigned long     u32_t; //32 bit type

typedef char               i8_t; //8 bit signed type
typedef short             i16_t; //16 bit signed type
typedef long              i32_t; //32 bit signed type

typedef struct { u32_t _[2]; } u64_t; //64 bit type
/* 磁盘，inode等数据结构中使用的类型 end */

/* The following types are needed because MINIX uses K&R style function
 * definitions (for maximum portability).  When a short, such as dev_t, is
 * passed to a function with a K&R definition, the compiler automatically
 * promotes it to an int.  The prototype must contain an int as the parameter,
 * not a short, because an int is what an old-style function definition
 * expects.  Thus using dev_t in a prototype would be incorrect.  It would be
 * sufficient to just use int instead of dev_t in the prototypes, but Dev_t
 * is clearer.
 */
typedef int               Dev_t;
typedef int          _mnx_Gid_t;
typedef int             Nlink_t;
typedef int          _mnx_Uid_t;
typedef int                U8_t;
typedef unsigned long     U32_t;
typedef int                I8_t;
typedef int               I16_t;
typedef long              I32_t;

/* ANSI C makes writing down the promotion of unsigned types very messy.  When
 * sizeof(short) == sizeof(int), there is no promotion, so the type stays
 * unsigned.  When the compiler is not ANSI, there is usually no loss of
 * unsignedness, and there are usually no prototypes so the promoted type
 * doesn't matter.  The use of types like Ino_t is an attempt to use ints
 * (which are not promoted) while providing information to the reader.
 */
typedef unsigned long       Ino_t;
#if _EM_WSIZE   == 2
//typedef unsigned int        Ino_t; Ino_t is now 32 bits
typedef unsigned int        Zone1_t;
typedef unsigned int      Bitchunk_t;
typedef unsigned int           U16_t;
typedef int               _mnx_Mode_t;
#else /* _EM_WSIZE == 4, or _EM_WSIZE undefined */
/* typedef int                  Ino_t is now 32 bits */
typedef int                  Zone1_t;
typedef int               Bitchunk_t;
typedef int                    U16_t;
typedef int              _mnx_Mode_t;
#endif //_EM_WSIZE == 2, etc

/* Signal handler type, e.g. SIG_IGN */
typedef void _PROTOTYPE((*sighandler_t), (int) );

/* 兼容其他系统 start */
typedef unsigned char       u_char;
typedef unsigned short      u_short;
typedef unsigned int        u_int;
typedef unsigned long       u_long;
typedef char                *caddr_t;
/* 兼容其他系统 start */

#endif //_TYPES_H