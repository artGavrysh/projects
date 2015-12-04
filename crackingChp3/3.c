/*
 *  Imagine a (literal) stack of plates. If the stack gets too high, it might topple. 
 *  Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. 
 *  Implement a data structure SetOfStacks that mimics this. 
 *  SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity. 
 *  SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack 
 *  (that is, pop() should return the same values as it would if there were just a single stack).
 */
#include <stdio.h>

#define BUF_LEN 16
#define STR_LEN 128 
#define MAX_STACK 4

static char buf[MAX_STACK][BUF_LEN];

typedef struct Stack
{
    int bottom;
    int top;
} Stack;

typedef struct SetOfStacks
{
    Stack set[MAX_STACK];
    int nStacks;
    int threshold; 
   
} SetOfStacks;

Stack createStack(int where)
{
    Stack stack = {.bottom = where, .top = where};
    return stack;
}

void pushEven(Stack *stack, int bufIdx, char c)
{
    if (buf[bufIdx][stack->top + 1] == '\0')
        buf[bufIdx][stack->top++] = c;
    else
    {
       printf("error: stackoverflow!\n");
       return;
    } 
}

void pushOdd(Stack *stack, int bufIdx, char c)
{
    if (buf[bufIdx][stack->top - 1] == '\0')
        buf[bufIdx][stack->top--] = c;
    else
    {
       printf("error: stackoverflow!\n");
       return;
    }
}

char popEven(Stack *stack, int bufIdx)
{
    char res;
    if ((stack->top - 1) >= stack->bottom)
    {
        res = buf[bufIdx][--stack->top];
        buf[bufIdx][stack->top + 1] = '\0';
        return res;
    }
    else
        return '\0';
}

char popOdd(Stack *stack, int bufIdx)
{
    char res;
    if ((stack->top + 1) <= stack->bottom)
    {
        res = buf[bufIdx][++stack->top];
        buf[bufIdx][stack->top - 1] = '\0';
        return res;
    }
    else
        return '\0';
}

char isEmpty(Stack *stack)
{
    return (stack->top == stack->bottom) ? 1 : 0;
}

SetOfStacks initSet(void)
{
    SetOfStacks stackSet = {.nStacks = 0, .threshold = BUF_LEN / 2};
    stackSet.set[stackSet.nStacks] = createStack(0);
    return stackSet;
}

void pushSet(char c, SetOfStacks *stackSet)
{
    Stack *current = &(stackSet->set[stackSet->nStacks]);
    if (stackSet->nStacks % 2) //odd
    {
        if ((current->bottom - current->top) < stackSet->threshold)
               pushOdd(current, stackSet->nStacks, c);
        else
        {
               if ((stackSet->nStacks + 1) < MAX_STACK)
               {
                    stackSet->nStacks++;
                    stackSet->set[stackSet->nStacks] = createStack(0);
                    pushEven(&(stackSet->set[stackSet->nStacks]), stackSet->nStacks, c);
               }
               else
               {
                   printf("Error: SET OVERFLOW\n");
                   return;
               }
        } 
    }
    else //even
    {
        if ((current->top - current->bottom) < stackSet->threshold)
               pushEven(current, stackSet->nStacks, c);
        else
        {
            if ((stackSet->nStacks + 1) < MAX_STACK)
            {
               stackSet->nStacks++;
               stackSet->set[stackSet->nStacks] = createStack(BUF_LEN - 1);
               pushOdd(&(stackSet->set[stackSet->nStacks]), stackSet->nStacks, c);
            }
            else
            {
               printf("Error: SET OVERFLOW\n");
               return;
            }
        }
    }
}

char popSet(SetOfStacks *stackSet)
{
    Stack *current = &(stackSet->set[stackSet->nStacks]);
    if (stackSet->nStacks % 2) //odd
    {
        if (!isEmpty(current))
            return popOdd(current, stackSet->nStacks);
        else
        {
            if ((stackSet->nStacks - 1) >= 0)
            {
                stackSet->nStacks--;
                return popEven(&(stackSet->set[stackSet->nStacks]), stackSet->nStacks);
            }
            else
                return '\0';
        }
    }
    else //even
    {
        if (!isEmpty(current))
            return popEven(current, stackSet->nStacks);
        else
        {
            if ((stackSet->nStacks - 1) >= 0)
            {
                stackSet->nStacks--;
                return popOdd(&(stackSet->set[stackSet->nStacks]), stackSet->nStacks);
            }
            else
                return '\0';
        }
    }
}

int main()
{
    int i;
    char c, longWord[STR_LEN];
    SetOfStacks set = initSet();

    scanf("%s", longWord);

    for (i = 0; longWord[i] != '\0'; ++i)
        pushSet(longWord[i], &set);

    while ((c = popSet(&set)) != '\0')
        printf("%c, ", c);
    printf("\n");

    return 0;
}

