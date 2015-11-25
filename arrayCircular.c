#include <stdio.h> 

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void shift(int *a, int n, int shift)
{
    int i, j, step, temp, lim;
    shift = shift % n;
    if (shift < 0)
        shift += n;
    step = gcd(n, shift); //gcd
    lim = step;
    while (lim <= shift)
    {
        for (i = 0; i < step; ++i)
        {
            temp  = a[n - i - 1];
            for (j = n - i - 1; j >= 0; j -= step)
                a[j + step] = a[j];
            a[step - i - 1] = temp;
        }
        lim += step;
    }
}

int main ()
{
    int i, N = 8;
    int M = 4;
	int v[8] = {1,2,3,4,5,6,7,8};
    
    shift(v, N, M);

    for (i = 0; i < 8; i++)
        printf("%d, ", v[i]);
    printf("\n");
	return 0;
}
