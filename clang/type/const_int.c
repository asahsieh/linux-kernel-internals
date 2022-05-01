/*
 * Program 6-17: Add const qualifier the type
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

    /* Get compilation error: assignment of read-only location */
    //*pi1 = 30;
    //*pi2 = 50;
}
