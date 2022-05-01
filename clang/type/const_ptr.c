/*
 * Program 6-19: The const-qualified version of a type “pointer to int”
 *
 * The pointer type is const-qualified.
 *
 * The program is from <C語言入門與進階教學> writen by NCTU teacher, 鄭昌杰
 *
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 10, y = 20;

    /*
     * the variable must to be initialized by a constant value,
     * or got an error: unintvar: Uninitilaized variable: pi
     */
    // int *const pi;
    int *const pi = &x;

    *pi += y;            /* OK,  可以間接修改 */
    printf("%d\n", *pi); /* OK,  可以間接讀取 */

    /* pi內容不可被修改! */
    /* error: try to modify a read-only variable */
    // pi = &y;

    return 0;
}
