/*
 * Design an algorithm and write code to remove the duplicate characters
 * in a string without using any additional buffer. One or two additional variables
 */
#include <stdio.h>

#define MAX_N 100

void move(char *v, int idx)
{
    for (idx; v[idx] != '\0'; ++idx)
        v[idx] = v[idx+1];
}

int main()
{
    int i, j;
    char buf[MAX_N];
    scanf("%s", buf);
    
    for(i = 0; buf[i] != '\0'; ++i)
        for(j = i + 1; buf[j] != '\0'; ++j)
            if (buf[i] == buf[j])
                move(buf, j);
    printf("%s\n", buf);   
    return 0;
}
