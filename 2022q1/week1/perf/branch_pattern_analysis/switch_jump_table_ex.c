/*
 * Reference **Jump table example in C** section on Wikipedia [Branch Table](https://en.wikipedia.org/wiki/Branch_table#Jump_table_example_in_C)
 *
 */

#define N 5000000

#include <stdio.h>
#include <stdlib.h>

typedef void (*Handler)(void);    /* A pointer to a handler function */

/* The functions */
void func3 (void) { printf( "3\n" ); }
void func2 (void) { printf( "2\n" ); }
void func1 (void) { printf( "1\n" ); }
void func0 (void) { printf( "0\n" ); }

Handler jump_table[4] = {func0, func1, func2, func3};

void test_0( int a )
{
  switch ( a )
  {
    case 0:
        jump_table[0](); 
        break;
    case 1:
        jump_table[1](); 
        break;
    case 2:
        jump_table[2](); 
        break;
    case 3:
        jump_table[3]();
        break;
    default:
      printf("Corrently no mapped function.\n");
      break;
  }
}


int main (int argc, char **argv) {
//    int value;
//
//    /* Convert first argument to 0-3 integer (modulus) */
//    value = atoi(argv[1]) % 4;
//
//    /* Call appropriate function (func0 thru func3) */
//    jump_table[value]();
    int i ;

    for (i = 0; i < N; i++) test_0(i%5);

    return 0;
}
