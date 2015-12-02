/* Implement an algorithm to determine
 * if a string has all unique characters. What if you can not use additional data structures?
 */
#include <stdio.h>
#include <string.h>

#define MAX_N 100

int main()
{
    char buf[MAX_N];

    scanf("%s", buf);
    int i, j, len = strlen(buf);
    char y = 0;
    for (i = 0; buf[i] != '\0'; ++i)
        for(j = i + 1; buf[j] != '\0'; ++j)
           if (buf[i] == buf[j])
              y = 1;
    if (y)
       printf("yes\n");
    else
       printf("no\n"); 
    return 0;
}
