#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[])
{
    int i = 2, j = 3;

    printf("Before `max` comparison: i=%d, j=%d\n", i, j);
    max(i++, j++);
    printf("After `max` comparison:  i=%d, j=%d\n", i, j);

    return 0;
}
