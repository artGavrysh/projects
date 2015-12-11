/*
 *  Write a method to generate the nth Fibonacci number.
 */
#include <stdio.h>

int getFibonacci(int n);
int getFibonacciIterative(int n);

int main()
{
    int n, i;

    scanf("%d", &n);

    printf("%d\n", getFibonacciIterative(n));

    return 0;
}

int getFibonacci(int n)
{
    if (n > 3)
        return getFibonacci(n-1) + getFibonacci(n-2);
    else if (n < 3 && n > 0)
        return n;
}

int getFibonacciIterative(int n)
{
    int i, buf[256];
    
    for (i = 0; i <= n; ++i)
    {
        if (i < 4)
            buf[i] = i;
        else
            buf[i] = buf[i-1] + buf[i-2];
    }
    return buf[n];
}
