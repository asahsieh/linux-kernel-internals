/* 請注意，C99以上的版本才可設計行內函式 */
#include <stddef.h>  // for size_t
#include <stdio.h>

extern void swap(int *, int *) __attribute__((always_inline)); /* swap的宣告 */
inline static void bbsort(int *, size_t); /* bbsort的宣告 */

static int swap_cnt = 0;

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

/* swap的定義。因為宣告端只有以extern指示，extern可有可無，但inline則必要 */
inline void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
    swap_cnt++;
}

/* bbosrt定義，static與inline可有可無，因為宣告端已指示 */
void bbsort(int *A, size_t n)
{
    size_t i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                swap(A + i, A + j);
            }
        }
    }
    printf("bbsort::swap_cnt=%d\n", swap_cnt);
}
