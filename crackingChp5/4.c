#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", ((n & (n-1)) == 0)); //evaluated if n is power of 2
    return 0;
}
