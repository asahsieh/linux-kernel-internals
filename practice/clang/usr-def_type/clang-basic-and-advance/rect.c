#include <stdio.h>
#include "union.h"

/*
 * Represent a rectangle by the left-top and the right-bottom points.
 *
 * To improve readiability, the anonymous struct in each union is to provide
 * property of the point (i.e., name of the point.)
 */
typedef struct rect {
    union {
        UPoint2D P1;
        struct {
            double left, top;
        };
    };
    union {
        UPoint2D P2;
        struct {
            double right, bottom;
        };
    };
} rect;

int main(int argc, char *argv[])
{
    rect rc = {{-5.0, 5.0}, {3.0, -3.0}};
    printf("Size of rect: %zu\n", sizeof(rect));
    printf("The left-top point of rect:     (%g, %g)\n", rc.left, rc.top);
    printf("The right-bottom point of rect: (%g, %g)\n", rc.right, rc.bottom);

    return 0;
}
