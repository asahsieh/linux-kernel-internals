/*
 * 程式10-34
 *
 * Description:  A column of asterisks on the left side,
 * with beginning and ending almost-blank lines.
 */

#include <stdio.h>

/*
 * data[0], x, y will share the same memory space
 */
typedef union UPoint2D {
    double data[2];
    double x, y;
} UPoint2D;

inline static void print_uP(UPoint2D uP);

int main(int argc, char *argv[])
{
    UPoint2D uP = {{0.1, 0.2}};

    printf("Size of the UPoint2D: %zu bytes\n", sizeof(uP));

    // Check the correctness of initialization on UPoint2D
    printf("\nInitial values of members in instance of UPoint2D, uP:\n");
    print_uP(uP);

    // Observed the behavior of sharing memory space
    printf("\nChange the value of the member 'data'\n");
    uP.data[0] = 0.2;
    uP.data[1] = 0.3;
    print_uP(uP);

    printf("\nScale up the values of the members 'x' and 'y' by 10 and 20\n");
    uP.x *= 10.0;
    uP.y *= 20.0;
    print_uP(uP);

    return 0;
}

void print_uP(UPoint2D uP)
{
    printf("uP.data[0]=%g\n", uP.data[0]);
    printf("uP.data[1]=%g\n", uP.data[1]);
    printf("uP.x=%g\n", uP.x);
    printf("uP.y=%g\n", uP.y);
}
