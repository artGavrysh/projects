/*
 * You have two numbers represented by a linked list, where each node contains a single digit. 
 * The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * EXAMPLE
 * Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
 * Output: 8 -> 0 -> 8
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

int append(Node* root, int newValue)
{
    int i = 0;
    Node *newNode, *copy = root;
    
    while (copy->next != NULL)
    {
        copy = copy->next;
        ++i;
    }

    if ((newNode = malloc(sizeof(Node))) == NULL)
       return 0;
    
    newNode->value = newValue;
    newNode->next = NULL;
    copy->next = newNode;
    return ++i;
} 

Node* populate(int number)
{
    int i;
    Node* root = malloc(sizeof(Node));
    
    while( number > 0)
    {
        i = number % 10;
        if (append(root, i) == 0)
            return NULL;
        number /= 10;
    }

    return root;  
}

Node* sum(Node *a, Node *b)
{
    Node* newNode, *copy = a;

    int sum = 0;
    while ( b->next != NULL)
    {
        b = b->next;
        sum += b->value;
        
        if (a->next != NULL)
        {
            a = a->next;
            sum += a->value;
        }
        else
        {
            if ((newNode = malloc(sizeof(Node))) == NULL)
                    return NULL;
            newNode->value = 0;
            newNode->next = NULL;
            a->next = newNode;
            a = a->next;
        }
        if (sum > 9)
        {
            a->value = sum % 10;
            sum = sum / 10;
        } 
        else
        {
            a->value = sum;
            sum = 0;
        }
    }

    return copy;
}

int main()
{
    int a, b;
    Node *listA, *listB, *res;

    scanf("%d %d", &a, &b);

    listA = populate(a);
    listB = populate(b);

    res = sum(listA, listB);

    while (res->next != NULL)
    {
        res = res->next;
        printf("%d", res->value);
    }
    printf("\n");

    return 0;
}
