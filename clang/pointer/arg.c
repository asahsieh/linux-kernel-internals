#include <stdio.h>
int main(int argc, char (*argv)[0])
{
    puts(((char **) argv)[0]);
    return 0;
}
