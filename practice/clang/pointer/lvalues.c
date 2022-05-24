#include <stdio.h>

int main()
{
    /*
    int a = 10;
    int *E = &a;

    ++(*E);   // a = a + 1
    ++(a++);  // error
    ++(&a++); // error
    */

    // Examples from:
    // https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
    //
    //

    /*
    // Basic
    //
    // mapped asm: movl   $0x4,-0x4(%rbp)
    // They can just reside in some temporary register for the duration of the
    computation.
    //
    int var = 4;
    */

    /*
    // For example, the unary '*' (dereference) operator takes an rvalue
    argument but produces an lvalue as a result. Consider this valid code: int
    arr[] = {1, 2}; int* p = &arr[0];
    *(p + 1) = 10;   // OK: p + 1 is an rvalue, but *(p + 1) is an lvalue
    */

    // Conversely, the unary address-of operator '&' takes an lvalue argument
    // and produces an rvalue:

    int var = 10;
    // int *bad_addr = &(var + 1); // ERROR: lvalue required as unary '&'
    // operand
    //  (var + 1) is temporary results of expressions, which don't have an
    //  identifiable memory location
    int *addr = &var;  // OK: var is an lvalue
    //&var = 40;                  // ERROR: lvalue required as left operand
    // of assignment
}
