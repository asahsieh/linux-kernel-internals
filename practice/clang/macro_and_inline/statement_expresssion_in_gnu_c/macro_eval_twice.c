#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[])
{
    int i = 2, j = 3, k, l, tmp;

    printf("=== To test the macro with inputs causing \"pitfall\"\n");
    printf(", `max(i++, j++)`===\n");

    do {
        k = i;
        l = j;

        printf("Before the comparison:\ti=%d, j=%d\n", k, l);
        if ((i++) > (j++)) {
            printf("In the comparison:\ti=%d, j=%d\n", i, j);
            (i++);
            if (i == (k + 2)) {
                printf("After the comparison:\ti=%d, j=%d\n\n", i, j);
                printf("[WARN] The expression are evaluated twice.\n");
                printf("The larger value `i` (%d) is incremented twice to (%d)",
                       k, i);
                goto EXANGE_INPUTS;
            }
        } else {
            printf("In the comparison:\ti=%d, j=%d\n", i, j);
            (j++);
            if (j == (l + 2)) {
                printf("After the comparison:\ti=%d, j=%d\n\n", i, j);
                printf("[WARN] The expression are evaluated twice.\n");
                printf("The larger value `j` (%d) is incremented twice to (%d)",
                       l, j);
                goto EXANGE_INPUTS;
            }
        }
        printf("[SAFE] The larger value %c is keep unchanged, ",
               (k > l ? i : j));
        printf("so The macro is evaluated safely.\n\n");

        goto TEST_MACRO_SAFE;

        // Exange the two inputs to observe the else statement
    EXANGE_INPUTS:
        tmp = j;
        j = i;
        i = tmp;

        printf("\n\n");
    } while (i > j);

TEST_MACRO_SAFE:
    printf("=== To test the macro with inputs make it \"safe\",\n");
    printf("`max(i,j)` ===\n");

    k = i;
    l = j;

    printf("Before the comparison:\ti=%d, j=%d\n", k, l);
    if ((i) > (j)) {
        printf("In the comparison:\ti=%d, j=%d\n", i, j);
        if (i == (k + 2)) {
            printf("After the comparison:\ti=%d, j=%d\n\n", i, j);
            printf("[WARN] The expression are evaluated twice.\n");
            printf("The larger value `i` (%d) is incremented twice to (%d)\n\n",
                   k, i);

            goto END_OF_TEST;
        }

    } else {
        printf("In the comparison:\ti=%d, j=%d\n", i, j);
        if (j == (l + 2)) {
            printf("After the comparison:\ti=%d, j=%d\n\n", i, j);
            printf("[WARN] The expression are evaluated twice.\n");
            printf("The larger value `j` (%d) is incremented twice to (%d)\n\n",
                   l, j);

            goto END_OF_TEST;
        }
    }
    printf("After the comparison:\ti=%d, j=%d\n\n", i, j);
    printf("[SAFE] The larger value %c is keep unchanged", (k > l ? 'i' : 'j'));
    printf(",\nso The macro is evaluated safely.\n\n");

END_OF_TEST:
    return 0;
}
