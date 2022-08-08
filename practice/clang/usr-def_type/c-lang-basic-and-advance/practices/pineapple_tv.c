// *****************************************************************************
// Questions of 1 to 3 on chapter 10
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR_STDIN                                 \
    while (((c = getchar()) != '\n') && (c != EOF)) \
        ;
#define EMPLOYEE_MEMBER_NUM 7

// The last element is used to specify the state/action is not supported yet.
typedef enum { STOP, PLAY, PAUSE, FAST_FORWARD, REWIND, UNSUP_STAT } TvStates;
typedef enum {
    ONCE,
    TWICE,
    THREE_TIMES,
    HELD_ON_THREE_SEC,
    UNSUP_ACT
} ButtomActions;

typedef struct employee {
    const unsigned int ID;
    /* violate the constraints 2 in ISO C99 6.7.2.1 */
    // char *name[];
    char name[100];
    unsigned int age;
    char birthday[100];
    unsigned int job_tenure;
    char address[100];
    unsigned int phone_number;
} Employee;

/*
 *
 */
static void TvFSM(TvStates *cur_stat, const ButtomActions action);

/*
 * Get members of Employee from standard input
 *
 * Return: an Employee object with values of members filled by inputs
 */

static void inputEmployee(Employee *pE);

/*
 * Output all members in an object of Employee
 */
static void outputEmployee(const Employee *pE);

int main(int argc, char *argv[])
{
    TvStates stat = STOP;
    Employee *pE = malloc(sizeof(Employee));

    printf("For question 1:\n");

    printf("Initial state=%d action=ONCE\n", stat);
    TvFSM(&stat, ONCE);
    printf("Intermediate state=%d action=THREE_TIMES\n", stat);
    TvFSM(&stat, THREE_TIMES);
    printf("Intermediate state=%d action=ONCE\n", stat);
    TvFSM(&stat, ONCE);
    printf("Intermediate state=%d action=UNSUP_ACT\n", stat);
    TvFSM(&stat, UNSUP_ACT);
    printf("Final state=%d\n", stat);

    printf("\nFor question 2:\n");
    inputEmployee(pE);
    outputEmployee(pE);

    free(pE);
    return 0;
}

void TvFSM(TvStates *cur_stat, const ButtomActions action)
{
    switch (*cur_stat) {
    case STOP:
        if (action == ONCE)
            *cur_stat = PLAY;
        else
            *cur_stat = UNSUP_STAT;
        break;
    case PLAY:
        if (action == THREE_TIMES)
            *cur_stat = REWIND;
        else
            *cur_stat = UNSUP_STAT;
        break;
    case REWIND:
        if (action == ONCE)
            *cur_stat = PLAY;
        else
            *cur_stat = UNSUP_STAT;
        break;
    default:
        printf("WARN: unsupported state: %0d !!!", *cur_stat);
        break;
    }
}


void inputEmployee(Employee *pE)
{
    int c, member_no = 0, is_num;

    puts("*** Enter information for the employee ***:");
    do {
        switch (member_no) {
        case 0:
            puts("Enter ID:");
            // modify the const member by pointer
            //
            // TODO: replace by macro
            do {
                is_num = scanf("%u", (unsigned int *) &pE->ID);
                puts("Not a number, please enter a number for ID:");
                CLEAR_STDIN;
            } while (!is_num);
            break;
        default:
            printf("Unimplemented input for member_no %0d.\n", member_no);
            return;
        }
        member_no++;
    } while (member_no < EMPLOYEE_MEMBER_NUM);
}

void outputEmployee(const Employee *pE)
{
    printf("*** Ouput the information of the employee ***:\n");
    for (int i = 0; i < EMPLOYEE_MEMBER_NUM; i++) {
        switch (i) {
        case 0:
            printf("ID: %u\n", pE->ID);
            break;
        default:
            printf("Unimplemented input for member_no %0d.\n", i);
            return;
        }
    }
}
