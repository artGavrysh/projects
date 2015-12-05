/*
 *  In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different sizes 
 *  which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom
 *  (e.g., each disk sits on top of an even larger one). 
 *  You have the following constraints:
 *  (A) Only one disk can be moved at a time.
 *  (B) A disk is slid off the top of one rod onto the next rod.
 *  (C) A disk can only be placed on top of a larger disk.
 *  Write a program to move the disks from the first rod to the last using Stacks.
 */
#include <stdio.h>

#define MAX_N   32
#define N_STACKS 4

static char buf[N_STACKS][MAX_N];

typedef struct Stack
{
    int root;
    int bottom;
    int top;
} Stack;

Stack createStack(int idx)
{
    Stack stack = {.root = idx, .bottom = 0, .top = 0};
    return stack;
}

void push(Stack *stack, char val)
{
    if ((stack->top + 1) != '\0')
        buf[stack->root][stack->top++] = val;
    else
        printf("stackoverflow\n");
}

char pop(Stack *stack)
{
    if ((stack->top-1) >= stack->bottom)
        return buf[stack->root][--stack->top];
    else
        return '\0';
}

void moveTower(int height, Stack *fromRod, Stack *toRod, Stack *withRod)
{
    char c;
    if (height >= 1)
    {
        moveTower(height-1, fromRod, withRod, toRod);
        if ((c = pop(fromRod)) != '\0') //what else?
             push(toRod, c);
        moveTower(height-1, withRod, toRod, fromRod);
    }
}

int main()
{
    int i, len;
    Stack rodA, rodB, rodC;
    char c = 'a';

    printf("Please enter the number of the disks: ");
    scanf("%d", &len);
    printf("\n");

    if (len > 26)
    {
        printf("Error: we have only 26 letter\n");
        return -1;
    }

    rodA = createStack(0);
    rodB = createStack(1);
    rodC = createStack(2);

    for (i = 0; i < len && c < 'z'; ++i)
        push(&rodB, c++);

    while((c = pop(&rodB)) != '\0')
        push(&rodA, c);

    //now we have three rods with disks from a in acending order on the first one
    //start the recursion
    moveTower(len, &rodA, &rodC, &rodB);
    
    printf("The disks on the final rod:\n");
    while ((c = pop(&rodC)) != '\0')
        printf("%c, ", c);
    printf("\n"); 

    return 0;
}
