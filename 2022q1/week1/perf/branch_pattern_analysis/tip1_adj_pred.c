/*
 * Implement Binary search (number of cases < 5) in
 *   [Branch Patterns, Using GCC](https://tinyurl.com/annm23jh)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int test( int a, int b, int c )
{
  if (__builtin_expect( (a == 0 ), 1 ))
  {
    return (b + c);
  }

  return (a + c);
}	

int main (int argc, char *argv[]) {

    test(0, 1, 2);

    return EXIT_SUCCESS; 
}
