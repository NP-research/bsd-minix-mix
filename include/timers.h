#ifndef _TIMERS_H
#define _TIMERS_H

#include <limits.h>
#include <sys/types.h>

struct timer;
typedef void (*tmr_func_t)(struct timer *tp);
typedef union { int ta_int; long ta_long; void *ta_ptr; } tmr_arg_t;

/* A timer_t variable must be declare for each distinct timer to be used.
 * The timers watchdog function and expiration time are automatically set
 * by the library function tmrs_settimer, but its argument is not.
 */
typedef struct timer
{
    struct timer	*tmr_next;	/* next in a timer chain */
    clock_t 	tmr_exp_time;	/* expiration time */
    tmr_func_t	tmr_func;	/* function to call when expired */
    tmr_arg_t	tmr_arg;	/* random argument */
} timer_t;

/* Used when the timer is not active. */
#define TMR_NEVER    ((clock_t) -1 < 0) ? ((clock_t) LONG_MAX) : ((clock_t) -1)
#undef TMR_NEVER
#define TMR_NEVER	((clock_t) LONG_MAX)

/* These definitions can be used to set or get data from a timer variable. */
#define tmr_arg(tp) (&(tp)->tmr_arg)
#define tmr_exp_time(tp) (&(tp)->tmr_exp_time)

/* Timers should be initialized once before they are being used. Be careful
 * not to reinitialize a timer that is in a list of timers, or the chain
 * will be broken.
 */
#define tmr_inittimer(tp) (void)((tp)->tmr_exp_time = TMR_NEVER, \
	(tp)->tmr_next = NULL)

/* The following generic timer management functions are available. They
 * can be used to operate on the lists of timers. Adding a timer to a list
 * automatically takes care of removing it.
 */
_PROTOTYPE( clock_t tmrs_clrtimer, (timer_t **tmrs, timer_t *tp, clock_t *new_head)		);
_PROTOTYPE( void tmrs_exptimers, (timer_t **tmrs, clock_t now, clock_t *new_head)		);
_PROTOTYPE( clock_t tmrs_settimer, (timer_t **tmrs, timer_t *tp,
clock_t exp_time, tmr_func_t watchdog, clock_t *new_head)				);

#endif /* _TIMERS_H */