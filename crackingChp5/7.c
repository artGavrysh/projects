/*
 *  An array A[1... n] contains all the integers from 0 to n except for one number which is missing.
 * In this problem, we cannot access an entire integer in A with a single operation. 
 * The elements of A are represented in binary, and the only operation we can use to access them 
 * is “fetch the jth bit of A[i]”, which takes constant time. Write code to find the missing integer. 
 * Can you do it in O(n) time?
 */
#include <stdio.h>

static int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 9};

int fetchJthBit(int i, int j)
{
    int res;
    int n = array[i];
    int k = 0;
    while (k++ < j)
        n /= 2;
    return n % 2;
}

void findMissing(int len)
{
    int i = 0;

    while (i < len)
    {
        if (fetchJthBit(i, 0) != i%2)
        {
            printf("Missing an integer at position: %d\n", i);
            return;
        }
        i++;
    }
}
    

int main()
{
    int N = 9;

    findMissing(N);

    return 0;
}
