/* Write code to reverse a C-Style String.
 * (C-String means that “abcd” is represented as five characters, including the null character.)
 */

#include <stdio.h>

#define MAX_N 100

int main()
{
    int i, j;
    char temp, buf[MAX_N];

    scanf("%s", buf);

    for(j = 0; buf[j] != '\0'; ++j)
        ;
    j--;
    for(i = 0; i < j; ++i, --j)
    {
       temp = buf[i];
       buf[i] = buf[j];
       buf[j] = temp;
    }
    printf("%s\n", buf);
    return 0;
} 
