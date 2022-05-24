#include "sort.h"

#ifdef SEMANTICS_5_EXTERN_DEF_IN_ANTHER_TRNS_UNIT
extern void swap(int *, int *);
#endif

/* 屬於sort.c的swap定義 */
void swap(int *pa, int *pb)
{
    printf("sort::swap\n");
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

/* bbsort的定義 */
inline void bbsort(int *A, size_t n)
{
    size_t i, j;

    if (!swap_cnt)
        swap_cnt = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                swap(A + i, A + j);
                swap_cnt++;
            }
        }
    }

    printf("bbsort::swap_cnt=%d\n", swap_cnt);
}
