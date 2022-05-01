#include <stdbool.h>
#include <stdio.h>

// warning: "true" redefined
// The order of sorted number will in DESCENDING order
#define true 0

/* SWAP的巨集定義 */
#define SWAP(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

// error: ‘t’ undeclared
/*
#define SWAP(a, b) \
    int t = a;     \
    a = b;         \
    b = t;         \
*/


void bbsort(int *A, size_t n)
{
    size_t i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((A[i] > A[j]) == true)
                SWAP(A[i], A[j]);
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
    printf("\n"); /* 2 4 6 7 8 9 */

    return 0;
}
