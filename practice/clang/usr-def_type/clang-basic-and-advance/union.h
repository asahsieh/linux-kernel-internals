#ifndef __UNION_H__
#define __UNION_H__

/*
 * Revisions:
 *   - data[0], x, y will share the same memory space
 *   - data[0] and x, data[1] and y, share the same memory space respectively
 */
typedef union UPoint2D {
    /* C11 support anonymous structures and unions */
    struct {
        double data[2];
    };
    struct {
        double x, y;
    };
} UPoint2D;

#endif
