/*
 * Program 6-20: Add const qualifier on both of type and indentifier.
 *
 * The program is from <C語言入門與進階教學> writen by NCTU teacher, 鄭昌杰
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 10, y = 20;
    const int *const pi1 = &x;
    const int *const pi2 = &y;

    /* 間接讀取 */
    printf("%d\n", *pi1);
    printf("%d\n", *pi2);

    /* 間接修改 */
    // Error: assignment of read-only location
    // '*(const int *)pi1'
    // The type pointed is a constant value,
    // it couldn't modified

    // *pi1 = *pi2;

    /* 修改指標的值: 交換兩個指標的值 */
    // Error: assignment of read-only variable pi1 and pi2

    // pi1 = pi2;
    // pi2 = &x;

    return 0;
}
