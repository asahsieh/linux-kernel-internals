/*
 * Program 6-18: Fix compiling error on assignment of (const int *) type
 *
 * By modifying values of the pointers (pointers’ addresses)
 *
 * The program is from <C語言入門與進階教學> writen by NCTU teacher, 鄭昌杰
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 10, y = 20;
    const int *pi1 = &x;
    int const *pi2 = &y;

    printf("%d\n", *pi1); /* 10，間接讀取OK */
    printf("%d\n", *pi2); /* 20，間接讀取OK */

    pi1 = pi2; /* Address of pointer */
    pi2 = &x;  /* could be modified. */

    printf("%d\n", *pi1); /* 20，pi1改指向y */
    printf("%d\n", *pi2); /* 10，pi2改指向x */

    return 0;
}
