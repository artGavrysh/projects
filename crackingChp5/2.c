/*
 *  Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation. 
 *  If the number can not be represented accurately in binary, print “ERROR”
 */
#include <stdio.h>

#define MAX_N 32

static char buf[MAX_N];

int main()
{
    char *it;
    char c, isFloat = 0, power = 1, sign = 0;
    int i, num = 0; 
    
    while ((c = getchar()) != EOF && c != '\0' && c != '\n')
    {
        if (c == '-')
            sign = 1;

        if (c == '.')
            isFloat = 1;
        
        if ('0' <= c && c <= '9')
        {
            num = num * 10 + (c - '0');
            if (isFloat)
                power--;
        }
    }
    printf("power: %d\n", power);
    
    i = MAX_N;
    while (num > 0 && i >=0)
    {
        buf[--i] = num % 2;
        num /= 2;

        if (isFloat && (MAX_N - i) > 23)
        {
            printf("ERROR\n");
            return -1;
        }
    }
    
    if (isFloat)
    {
        i = MAX_N - 23;
        power *= -1;
        while (power > 0 && i >= 0)
        {
            buf[--i] = power % 2;
            power /= 2;
        }
        if (power > 0)
        {
            printf("ERROR\n");
            return -1;
        }
    }
    if(sign)
        buf[0] = sign;

    for (i = 0; i < MAX_N; ++i)
        printf("%d", buf[i]);
    printf("\n");
        
    return 0;
}
    
        

