/*
 *  Write a method that returns all subsets of a set.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** getSubset(char *set, int *len);

int main()
{
    int n, i;
    char c = 'a', buf[26];
    char **res;
    
    scanf("%d", &n);

    for (i = 0; i < n && c <= 'z'; ++i)
        buf[i] = c++;
    buf[n] = '\0';

    res = getSubset(buf, &n);
    for (i = 0; i < n; ++i)
        printf("%s\n", res[i]);

    return 0;
}

char** getSubset(char *set, int *len)
{
    char c, **buf;
    int i, tmp;
    if (1 == *len)
    {
        tmp = 2;
        buf = malloc(tmp * sizeof(char*));
        buf[0] = malloc(sizeof(char));
        buf[1] = malloc(sizeof(char));
        buf[1] = strncpy(buf[1], set, *len);
        *len = tmp;
        
        return buf;
    }
    else
    {
        c = set[*len - 1];
        tmp = *len - 1;
        buf = getSubset(set, &tmp);
        buf = realloc(buf, 2 * tmp * sizeof(char**));
        for(i = tmp; i < 2*tmp; ++i)
        {
            buf[i] = malloc(*len * sizeof(char));
            buf[i] = strncpy(buf[i], buf[i - tmp], strlen(buf[i-tmp]));
            buf[i][strlen(buf[i-tmp])] = c;
            buf[i][strlen(buf[i-tmp])+1] = '\0';
        }
        *len = 2 * tmp; 

        return buf;
    }
}
