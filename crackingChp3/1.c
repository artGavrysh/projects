/*
 *  Describe how you could use a single array to implement three stacks.
 *
 */
#include <stdio.h>

#define BUF_LEN 16
#define STR_LEN 32 

static char buf[BUF_LEN];

typedef struct Stack
{
    int bottom;
    int top;
} Stack;

Stack stackA = {.bottom = 0, .top = 0};
Stack stackB = {.bottom = BUF_LEN - 1, .top = BUF_LEN - 1};
Stack stackC = {.bottom = BUF_LEN / 2, .top = BUF_LEN / 2};

void pushA(char c)
{
    if (buf[stackA.top + 1] == '\0')
        buf[stackA.top++] = c;
    else
    {
       printf("error: stackoverflow stackA!\n");
       return;
    } 
}

void pushB(char c)
{
    if (buf[stackB.top - 1] == '\0')
        buf[stackB.top--] = c;
    else
    {
       printf("error: stackoverflow stackB!\n");
       return;
    }
}

void pushC(char c)
{
    int i, len;
    if (buf[stackC.top + 1] == '\0')
        buf[stackC.top++] = c;
    else if (buf[stackC.bottom - 1] == '\0')//shift operation
    {
        len = stackC.top - stackC.bottom;
        i = stackC.bottom - 1;
        while (buf[--i] == '\0')
            ;
        stackC.bottom = (stackC.bottom - i) / 2;
        for (i = 0; i < len; ++i)
        {
            buf[stackC.bottom + i] = buf[stackC.top - len + i];
            buf[stackC.top - len + i] = '\0';
        }
        stackC.top = stackC.bottom + i;
        buf[stackC.top++] = c;
    }
    else
    {
       printf("error: stackoverflow stackC!\n");
       return;
    }
} 

int main()
{
    int i, j, k, mid;
    char strA[STR_LEN];
    char strB[STR_LEN];
    char strC[STR_LEN];

    scanf("%s %s %s", strA, strB, strC);
    for (i = 0; strA[i] != '\0'; ++i)
        pushA(strA[i]);

    for (j = 0; strB[j] != '\0'; ++j)
        pushB(strB[j]);

    for (k = 0; strC[k] != '\0'; ++k)
        pushC(strC[k]);
    
    for (i = 0 ; i < BUF_LEN; ++i)
        printf("%c", buf[i]);
    printf("\n");

    return 0;
}
