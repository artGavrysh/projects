/*
 *  Given an integer, print the next smallest and next largest number that have the same number 
 *  of 1 bits in their binary representation.
 */
#include <stdio.h>

#define SIZE_INT   16 

int main()
{
    int n, mask, counter = 0;
    scanf("%d", &n);

    while (n > 0)
    {
        if(n % 2)
            counter++;
        n /= 2;
    }
    printf("%d\n", counter);

    mask = 0xffff >> (SIZE_INT - counter);
    printf("The smallest number is: %d\n", mask);
    mask = mask << (SIZE_INT - counter);
    printf("The smallest number is: %d\n", mask);

    return 0;
}
