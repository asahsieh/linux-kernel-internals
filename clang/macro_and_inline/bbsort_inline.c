/* 請注意，C99以上的版本才可設計行內函式 */
#include <stddef.h>  // for size_t
#include <stdio.h>

inline static void swap(int *, int *); /* swap的宣告 */
extern void bbsort(int *, size_t);     /* bbsort的宣告 */

#ifdef CONS_3_SAME_TRANS_UNIT
static int swap_cnt = 0;
#endif

int main(int argc, char *argv[])
{
    int A[] = {7, 2, 4, 6, 9, 8};
    size_t i = 0, n = sizeof(A) / sizeof(int);
    bbsort(A, n);

    for (i = 0; i < n; ++i)
        printf("%d ", A[i]);
    printf("\n"); /* 2 4 6 7 8 9*/

    return 0;
}

/* swap定義，static與inline可有可無，因為宣告端已指示 */
void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

/* bbsort的定義。因為宣告端只有以extern指示，extern可有可無，但inline則必要 */
inline void bbsort(int *A, size_t n)
{
    size_t i, j;

#ifndef CONS_3_SAME_TRANS_UNIT
    static int swap_cnt = 0;
    printf("CONS_3_SAME_TRANS_UNIT isn't defined.\n");
#endif
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
