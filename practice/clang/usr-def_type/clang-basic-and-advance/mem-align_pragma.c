/*
 * C語言入門與進階教學- 鄭昌杰
 * 程式 10-31
 *
 * Description: Observe the memory aligment operation applied on `struct`
 *
 */
#include <stdio.h>
#pragma pack(push, 1) /* 儲存目前的對齊數，並改以1 byte 來對齊*/

/* Definition of Student_flo */
typedef struct Student_flo {
    int ID;               /* int, 4 bytes */
    char gender;          /* char, 1 byte */
    float height, weight; /* two float types, 8 bytes */
} Student_flo;

#pragma pack(pop) /* 取出先前儲存的對齊數*/
/* Definition of Student_dou */
typedef struct Student_dou {
    int ID;                /* int, 4 bytes */
    char gender;           /* char, 1 byte */
    double height, weight; /* two double types, 16 bytes */
} Student_dou;

/* main function */
int main(int argc, char *argv[])
{
    printf("%zu\n", sizeof(Student_flo));          /* 13 */
    printf("%zu\n", sizeof(struct Student_dou));   /* 21 */
    printf("%zu\n", _Alignof(Student_flo));        /*  1, as the same as
                                                      the setting number, 1,
                                                      in #pragma pack()      */
    printf("%zu\n", _Alignof(struct Student_dou)); /* should be 8 on
                                                      word size == 8 bytes   */
    return 0;
}
