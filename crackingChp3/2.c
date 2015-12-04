/*
 *  How would you design a stack which, in addition to push and pop, 
 *  also has a function min which returns the minimum element? 
 *  Push, pop and min should all operate in O(1) time.
 */
#include <stdio.h>

#define BUF_LEN 128 
#define STR_LEN 32 

static char buf[BUF_LEN];

typedef struct Stack
{
    int bottom;
    int top;
    char minElem;
} Stack;

Stack stackA = {.bottom = 0, .top = 0, .minElem = 'z'};

void pushA(char c)
{
    if (buf[stackA.top + 1] == '\0')
    {
        if (c < stackA.minElem)
            stackA.minElem = c;
        buf[stackA.top++] = c;
    }
    else
    {
       printf("error: stackoverflow stackA!\n");
       return;
    } 
}

char popA(void)
{
    if ((stackA.top - 1) >= stackA.bottom)
        return buf[--stackA.top];
    else
        return '\0';
}

char min(void)
{
    return stackA.minElem;
}

int main()
{
    int i;
    char c, str[STR_LEN];

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; ++i)
        pushA(str[i]);
/* 
    while ((c = popA()) != '\0')
        printf("%c, ", c);
    printf("\n");
*/
    printf("%c\n", min());
    return 0;
}
