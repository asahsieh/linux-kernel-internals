#ifndef SORT_H
#define SORT_H
#include <stddef.h>  // for size_t
#include <stdio.h>
#ifndef SEMANTICS_5_EXTERN_DEF_IN_ANTHER_TRNS_UNIT
inline static void swap(int *, int *);
#endif
extern void bbsort(int *, size_t);
static int swap_cnt;
#endif
