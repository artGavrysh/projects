/*
 * Write a function to determine the number of bits required to convert integer A to integer B.
 * Input: 31, 14
 * Output: 2
 */
#include <stdio.h>

int main()
{
    int i = 0, a, b, tmp;
    scanf("%d %d", &a, &b);
    
    tmp = a^b;
    while(tmp > 0)
    {
        if(tmp%2)
            i++;
        tmp /= 2;
    }
    printf("%d\n", i);

    return 0;
}

