#include <stdio.h>

int B = 2;
void func(int **p)
{
    *p = &B;
}
int main()
{
    int A = 1, C = 3;
    int *ptrA = &A;
    func(&ptrA);
    printf("%d\n", *ptrA);
    return 0;
}
