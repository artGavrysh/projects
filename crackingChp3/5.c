/*
 *  Implement a MyQueue class which implements a queue using two stacks
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

char isEmpty(Stack *stack)
{
    return (stack->top == stack->bottom) ? 1 : 0;
}

typedef struct Queue
{
    Stack stackA;
    Stack stackB;
} Queue;

Queue createQueue(void)
{
    Queue queue;
    queue.stackA = createStack(0);
    queue.stackB = createStack(1);
    return queue;
     
}

void enqueue(Queue *queue, char c)
{
    push(&(queue->stackA), c);
}

char dequeue(Queue *queue)
{
    char c;
    if (!isEmpty(&(queue->stackB)))
        return pop(&(queue->stackB));
    else
    {
       if (!isEmpty(&(queue->stackA)))
       {
          while((c = pop(&(queue->stackA))) != '\0')
             push(&(queue->stackB),c);
          return pop(&(queue->stackB));
       }
       else
           return '\0';
    }
}

int main()
{
    int i, len;
    Queue queue;
    char c = 'a';

    scanf("%d", &len);

    if (len > 25)
    {
        printf("error: we have only 26 letters\n");
        return -1;
    }

    queue = createQueue();

    for (i = 0; i < len && c <= 'z'; ++i)
        enqueue(&queue, c++);
    
    while ((c = dequeue(&queue)) != '\0')
        printf("%c, ", c);
    printf("\n");

    return 0;
}
