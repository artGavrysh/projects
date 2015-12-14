/*
 * You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. 
 * Write a method to merge B into A in sorted order. 
 */
#include <stdio.h>

#define N 16

static char arrayA[N] = "aceg";
static char arrayB[] = "bdfi";

int main()
{
    int i = 0, j = 0, k;
    
    while (arrayA[i] != '\0' && arrayB[j] != '\0')
    {
       printf("%c <-> %c ", arrayA[i], arrayB[j]);
       if (arrayA[i] >= arrayB[j])
       {
           printf("Yes\n");
           k = i;
           while (arrayA[k++] != '\0')
               ;
           arrayA[k] = '\0';
           while (k > i)
           {
               arrayA[k] = arrayA[k - 1];
               k--;
           }
           arrayA[i] = arrayB[j];
           i++;
           j++;
       }
       else
       {
           printf("No\n");
           i++;
       }
    }

    printf("%s\n", arrayA);

    return 0;
}
