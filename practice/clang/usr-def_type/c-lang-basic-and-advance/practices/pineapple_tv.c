// *****************************************************************************
// Questions of 1 to 3 on chapter 10
// *****************************************************************************
#include <stdio.h>

// The last element is used to specify the state/action is not supported yet.
typedef enum { STOP, PLAY, PAUSE, FAST_FORWARD, REWIND, UNSUP_STAT } TvStates;
typedef enum {
    ONCE,
    TWICE,
    THREE_TIMES,
    HELD_ON_THREE_SEC,
    UNSUP_ACT
} ButtomActions;

/*
 *
 */
static void TvFSM(TvStates *cur_stat, const ButtomActions action);

int main(int argc, char *argv[])
{
    TvStates stat = STOP;
    printf("Initial state=%d action=ONCE\n", stat);
    TvFSM(&stat, ONCE);
    printf("Intermediate state=%d action=THREE_TIMES\n", stat);
    TvFSM(&stat, THREE_TIMES);
    printf("Intermediate state=%d action=ONCE\n", stat);
    TvFSM(&stat, ONCE);
    printf("Intermediate state=%d action=UNSUP_ACT\n", stat);
    TvFSM(&stat, UNSUP_ACT);
    printf("Final state=%d\n", stat);

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
