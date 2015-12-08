/*
 * Write a program to swap odd and even bits in an integer with as few instructions 
 * as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc).
 */
#include <stdio.h>

int main()
{
    int a, b, maskOdd, maskEven;
    char firstBit = 0;
    scanf("%d", &a);

    maskOdd = a & 0x5555;
    maskEven = a & 0xaaaa;
    maskOdd = maskOdd << 1;
    maskEven = maskEven >> 1;

    b = maskOdd | maskEven;
 
    printf("%d\n", b);

    return 0;
}  


