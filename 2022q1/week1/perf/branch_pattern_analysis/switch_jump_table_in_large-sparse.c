/*
 * Implement Jump table by using GCC's &&label_name syntax 
 *   [Branch Patterns, Using GCC](https://tinyurl.com/annm23jh)
 */

#define N 5000000

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void call_0() {}
void call_1() {}
void call_2() {}
void call_3() {}

void test_0( int a )
{
  switch ( a )
  {
    case 0x0001:
        call_0();
        break;
    case 0x010B:
        call_1();
        break;
    case 0x2507:
        call_2();
        break;
    case 0xFCDF:
        call_3();
        break;
    default:
      printf("Corrently no mapped function.\n");
      break;
  }
}

int main (int argc, char *argv[]) {
    int i;

    for (i = 0; i < N; i++) test_0(i);

    return EXIT_SUCCESS; 
}
