/*
 * C語言入門與進階教學- 鄭昌杰
 * 程式 10-31
 *
 * Description: Observe the memory aligment operation applied on `struct`
 *
 */
#include <stdio.h>
/* Definition of Student_flo */
typedef struct Student_flo {
    int ID;               /* int, 4 bytes */
    char gender;          /* char, 1 byte */
    float height, weight; /* two float types, 8 bytes */
} Student_flo;

/* Definition of Student_dou */
typedef struct Student_dou {
    int ID;                /* int, 4 bytes */
    char gender;           /* char, 1 byte */
    double height, weight; /* two double types, 16 bytes */
} Student_dou;

/* main function */
int main(int argc, char *argv[])
{
    printf("%zu\n", sizeof(Student_flo));          /* should be 4x4 on the word
                                                      size >= 4 bytes, not 13 */
    printf("%zu\n", sizeof(struct Student_dou));   /* should be 6x4 on the word
                                                      size >= 4 bytes, not 21 */
    printf("%zu\n", _Alignof(Student_flo));        /* should be 4 on
                                                      word size == 4 bytes    */
    printf("%zu\n", _Alignof(struct Student_dou)); /* should be 8 on
                                                      word size == 8 bytes    */
    return 0;
}
