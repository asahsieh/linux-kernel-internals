#include <stdio.h>
#include <stdlib.h>

#define ERROR_INJECT 0

// setBit - set a bit of an integer
// Inputs: the integer, the index of bit to be set, the bit value to be set
// Return: the updated integer
//
// A bit of an integer can be set by doing OR with ‘1’,
// an one-hot mask is created, and the single high (1) bit is set on the index
// by left shifting
//
int setBit(int n, int index)
{
    int mask = (1 << index);
    return (n | mask);
}

// Inputs: the integer, the index of bit to be set, the bit value to be set
// Return: the updated integer
//
// The clear operation can be considered the opposite operation
//
int clearBit(int n, int index)
{
    int mask = ~(1 << index);
    return (ERROR_INJECT == 0) ? (n & mask) : (n ^ mask);
}

// Test set and clear on bit 3:
// on set: 0 -> 1
// on clear: 1 -> 0
// clearBit(1->0) -> setBit(0->1)
// Compare the updated num and the original num

int main(int argc, char *argv[])
{
    // 0b’1’010
    int num = 10, index = 3;
    int num_orig = num;

    num = clearBit(num, index);
    num = setBit(num, index);
    printf(
        "The number %#x after executing clearBit() and setBit() "
        "on the bit[%0d],\nwhich%sequalls to the the origin number %#x\n",
        num, index, ((num == num_orig) ? " " : " NOT "), num_orig);
}
