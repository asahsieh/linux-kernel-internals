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
#ifndef SOLUTION_2
#define swap(t, x, y)                                                         \
    {                                                                         \
        t _z;                                                                 \
        printf("In swap(): Original values:\tx=%d\ty=%d\t_z=%d\n", x, y, _z); \
        _z = y;                                                               \
        printf("In swap(): Assign y to z:\tx=%d\ty=%d\t_z=%d\n", x, y, _z);   \
        y = x;                                                                \
        x = _z;                                                               \
        printf("In swap(): Exanged values:\tx=%d\ty=%d\t_z=%d\n", x, y, _z);  \
    }
#else
/*
 * Sol_2: Use `typeof()` on `t`
 */
#define swap(t, x, y) \
    {                 \
        typeof(t) _z; \
        _z = y;       \
        y = x;        \
        x = _z;       \
    }
#endif

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

    printf("Original values:\t\ty=%d\tx=%d\n", y, x);
    swap(int, y, x);
    printf("Exchanged values:\t\ty=%d\tx=%d\n\n", y, x);
    printf("Original values:\t\t_z=%d\tx=%d\n", _z, x);
    swap(int, _z, x);
    printf("Exchanged values:\t\t_z=%d\tx=%d\n", _z, x);

    return 0;
}
