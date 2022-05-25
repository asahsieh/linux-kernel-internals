#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[])
{
    int i = 2, j = 3, k, l, tmp;
    // max(i++, j++);
    // ((i++) > (j++) ? (i++) : (j++));
    printf("=== To test the macro with inputs causing \"pitfall\"");
    printf(", `max(i++, j++)`===\n");

    do {
        k = i;
        l = j;
        printf("Before the comparison:\ti=%d, j=%d\n", k, l);
        if ((i++) > (j++)) {
            printf("In the comparison:\ti=%d, j=%d\n", i, j);
            (i++);
            if (i == (k + 2)) {
                printf("[WARN] The expression are evaluated twice.\n");
                printf("The larger value (%d) is incremented twice to (%d)\n\n",
                       k, i);
                goto EXANGE_INPUTS;
            }

        } else {
            printf("In the comparison:\ti=%d, j=%d\n", i, j);
            (j++);
            if (j == (l + 2)) {
                printf("[WARN] The expression are evaluated twice.\n");
                printf("The larger value (%d) is incremented twice to (%d)\n\n",
                       l, j);
                goto EXANGE_INPUTS;
            }
        }
        printf("The macro is evaluated safely.\n\n");
        goto TEST_MACRO_SAFE;

        // Exange the two inputs to observe the else statement
    EXANGE_INPUTS:
        tmp = j;
        j = i;
        i = tmp;
    } while (i > j);

TEST_MACRO_SAFE:
    printf("=== To test the macro with inputs make it \"safe\", ");
    printf("`max(i,j)` ===\n");
    k = i;
    l = j;
    printf("Before the comparison:\ti=%d, j=%d\n", k, l);
    if ((i) > (j)) {
        printf("In the comparison:\ti=%d, j=%d\n", i, j);
        if (i == (k + 2)) {
            printf("[WARN] The expression are evaluated twice.\n");
            printf("The larger value (%d) is incremented twice to (%d)\n\n", k,
                   i);

            goto END_OF_TEST;
        }

    } else {
        printf("In the comparison:\ti=%d, j=%d\n", i, j);
        if (j == (l + 2)) {
            printf("[WARN] The expression are evaluated twice.\n");
            printf("The larger value (%d) is incremented twice to (%d)\n\n", l,
                   j);

            goto END_OF_TEST;
        }
    }
    printf("The macro is evaluated safely.\n");

END_OF_TEST:
    return 0;
}
