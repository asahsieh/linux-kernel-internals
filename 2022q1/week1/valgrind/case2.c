#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    /* 1. Invalid write */
    char *str = malloc(4);
    strcpy(str, "Briant");
    free(str);

    /* 2. Invalid read */
    int *arr = malloc(3);
    printf("%d", arr[4]);
    free(arr);

    /* 3. Invalid read */
    printf("%d", arr[0]);

    /* 4. Invalid free */
    free(arr);
    return 0;
}
