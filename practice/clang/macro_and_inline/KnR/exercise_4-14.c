/*
 * **Exercise  4-14.** in K&R C, 2nd
 *
 * Description:
 *
 * Define a macro `swap(t,x,y)` that interchanges two arguments of type t.
 * (Block structure will help)
 */

#include <stdio.h>

/*
 * Sol_1: the answer from appendix of the textbook:
 *
 * Use `t` as a type to declare a variable directly
 *
 */
#define swap(t, x, y) \
    {                 \
        t _z;         \
        _z = y;       \
        y = x;        \
        x = _z;       \
    }

/*
 * Use macro to interchange values in variables
 *
 * Use the same name for the variable argument/parameter: _z
 */
int main(int argc, char *argv[])
{
    int x = 10;
    int y = 5;
    int _z = 15;

    printf("Original values:\tx=%d\ty=%d\n", x, y);
    swap(int, y, x);
    printf("Exchanged values:\tx=%d\ty=%d\n", x, y);
    printf("Original values:\tx=%d\t_z=%d\n", x, _z);
    swap(int, _z, x);
    printf("Exchanged values:\tx=%d\t_z=%d\n", x, _z);

    return 0;
}
