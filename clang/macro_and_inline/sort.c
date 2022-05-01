#include "sort.h"

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

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                swap(A + i, A + j);
            }
        }
    }
}
