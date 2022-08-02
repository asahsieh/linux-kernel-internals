/*
 * C語言入門與進階教學- 鄭昌杰
 * 程式 10-31
 *
 * Description: Observe the memory aligment operation applied on `struct`
 *
 */
#include <stdio.h>
/* Definition of Student */
typedef struct Student {
    int ID;               /* int, 4 bytes */
    char gender;          /* char, 1 byte */
    float height, weight; /* two float types, 8 bytes */
} Student;

/* main function */
int main(int argc, char *argv[])
{
    printf("%zu\n", sizeof(Student)); /* should be 16, not 13 */
    return 0;
}
