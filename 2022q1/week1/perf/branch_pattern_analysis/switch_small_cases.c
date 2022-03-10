/*
 * Implement Binary search (number of cases < 5) in
 *   [Branch Patterns, Using GCC](https://tinyurl.com/annm23jh)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void call_0() { printf("call_0() is called\n"); }
void call_1() { printf("call_1() is called\n"); }
void call_2() { printf("call_2() is called\n"); }
void call_3() { printf("call_3() is called\n"); }

void test_0( int a )
{
  switch ( a )
  {
    case 0:
      call_0();
      break;
    case 1:
      call_1();
      break;
    case 2:
      call_2();
      break;
    case 3:
      call_3();
      break;
    default:
      printf("Corrently no mapped function.\n");
      break;
  }
}

int main (int argc, char *argv[]) {
    /* long int strtol (const char* str, char** endptr, int base); */
    int in_val = 0;
    char str[100];

    // Put code which more likely to be executed in if block
    if (argc == 2)
    {
        strcpy(str, argv[1]);
    }
    else
    {
        printf("Please give an input value: ");
        scanf("%s", str);
    }

    in_val = atoi(str); 
    printf("The input value is: %d.\n", in_val);

	test_0(in_val);

    return EXIT_SUCCESS; 
}
