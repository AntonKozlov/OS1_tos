#ifndef TOS_H
#define TOS_H

#define TOS_MAX_THREAD 5

extern void tos_init(void);

extern void tos_sleep(int msec);

extern /*msec*/ int tos_gettime(void);

extern int tos_add_thread(void (*start_fn)(void *), void *param);

extern int tos_start(void);

#endif /* TOS_H */

