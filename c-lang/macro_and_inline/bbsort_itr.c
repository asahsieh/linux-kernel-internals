#include <stdio.h>

void bbsort(int *A, size_t n)
{
    size_t i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                int t = A[i]; /* Swap(A+i, A+j) */
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

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
