#include <stdio.h>

struct rec {
    int i;
    int j;
    int a[2];
    int *p;
};

int main(int argc, char *argv[])
{
    struct rec rec_inst;

    rec_inst.j = 1024;

    // Copy value of element r->i to r->j
    rec_inst.i = rec_inst.j;

    return 0;
}
