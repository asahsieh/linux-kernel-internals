#include <stdio.h>

// fptr is a pointer, point to a function
void (*fptr)();

// an empty function
void test()
{
    ;
}

int main()
{
    fptr = test;
    printf("test: %x, fptr: %x\n", test, fptr);
    return 0;
}
