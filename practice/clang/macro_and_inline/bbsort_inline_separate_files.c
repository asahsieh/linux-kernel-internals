#include "sort.h"

#ifdef SEMANTICS_5_EXTERN_DEF_IN_ANTHER_TRNS_UNIT
inline static void swap(int *, int *);
#endif

int main(int argc, char *argv[])
{
    int A[] = {7, 2, 4, 6, 9, 8};
    size_t i = 0, n = sizeof(A) / sizeof(int);
    swap(A, A + 1);                  /* main::swap */
    printf("%d %d\n", *A, *(A + 1)); /* 2 7 */
    bbsort(A, n);

    for (i = 0; i < n; ++i)
        printf("%d ", A[i]);
    printf("\n"); /* 2 4 6 7 8 9*/

    return 0;
}

/* 屬於main的swap定義 */
void swap(int *pa, int *pb)
{
    printf("main::swap\n");
    int t = *pa;
    *pa = *pb;
    *pb = t;
}
