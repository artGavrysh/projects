#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAXLINE 1000 
#define QUANT   20

int readlines(char *lineptr[], char *store, int max);
int m_getline(char *line, int max);

/*find: print lines that match pattern from 1st arg */
int main (int argc, char* argv[])
{
    char *lineptr[MAXLINE]; /*pointers to strings*/
    char storage[MAXLINE*QUANT];
    long lineno = 0;
    char c;
    int  i, nlines, n = 0, sign = 1;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        if ((c = *(argv[0]+1)) == '-')
        {
            sign = -1;
            ++argv[0];
        }
        while ((c = *++argv[0]) != '\0' && '0' <= c && c <= '9') 
                n = n * 10 + (c - '0');
        n *= sign;
        printf("debug: %d\n", n);
    }
    
    while ((nlines = readlines(lineptr, storage, QUANT)) > 0)
        {
            printf("Print the last %d lines:\n", n);
            i = nlines > n ? (nlines - n) : 0;
            while (i < nlines)
                printf("%s\n", lineptr[i++]);
        }
    return 0;
}

int readlines(char *lineptr[], char *store, int max)
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = m_getline(line, MAXLINE)) > 1)
    {
        printf("debug: %d: %s\n", len, line);
        if (nlines >= max || (p = malloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p; 
        }
    }
    return nlines;
}

int m_getline (char *line, int max)
{
    int c, i = 0;
    while (i < max-1 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
