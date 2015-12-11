/*
 *  Write a method to compute all permutations of a string.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** getPermutation(char* str, int *len);
char* insert(char* str, char c, int position);

int main()
{
    int i, n;
    char c = 'a', buf[26];
    char **result;
    
    scanf("%d", &n);

    for (i = 0; i < n && c <= 'z'; ++i)
        buf[i] = c++;
    buf[n] = '\0';

    result = getPermutation(buf, &n);

    for (i = 0; i < n; ++i)
        printf("%s\n", result[i]);

    return 0;
}

char** getPermutation(char* str, int *len)
{
    char **smallBuf, **largeBuf;
    char c;
    int tmp, i, j;

    if (*len == 1)
    {
        smallBuf = malloc(sizeof(char*));
        smallBuf[0] = malloc(sizeof(char));
        smallBuf[0] = strncpy(smallBuf[0], str, *len);
        smallBuf[0][*len] = '\0'; 
        return smallBuf;
    }
    else
    {
        c = str[*len - 1];
        tmp = *len - 1;
        smallBuf = getPermutation(str, &tmp);
        largeBuf = malloc(*len * tmp * sizeof(char*));
        for (i = 0; i < tmp; ++i)
        {
            for (j = 0; j < *len; ++j)
            {
                largeBuf[*len * i + j] = insert(smallBuf[i], c, j);
            }
            free(smallBuf[i]);
        }
        free(smallBuf);
        *len *= tmp;
        return largeBuf;
    }
}

char* insert(char* str, char c, int position)
{
    if (position > strlen(str))
            return NULL;

    int len = strlen(str);
    char *buf = malloc(len + 1);
    buf = strncpy(buf, str, position);
    buf[position] = c;
    strncpy(&buf[position+1], &str[position], len - position);
    buf[len+1] = '\0';
    return buf;
}
