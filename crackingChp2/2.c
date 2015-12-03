/*
 * Implement an algorithm to find the nth to last element of a singly linked list.
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

Node* populate(int len)
{
    int i;
    Node* root = malloc(sizeof(Node));
    
    for(i = 0; i < len; ++i)
        if (append(root, i) == 0)
            return NULL;

    return root;  
}

Node* push_back(Node* queue, int len, int val)
{
    int i;
    Node* temp;

    if ((i = append(queue, val)) == 0)
        return NULL;
    else if (i > len)
    {
        temp = queue;
        queue = queue->next;
        free(temp);
    }
    return queue;
}

int main()
{
    int n, len;
    Node *queue, *root; 

    scanf("%d %d", &len, &n);

    if (n > len)
        return -1;
    
    root = populate(len);
    queue = root;
    while (queue->next != NULL)
    {
        queue = queue->next;
        printf("%d, ", queue->value);
    }
    printf("\n");

    //in general we don't know how long the list is
    queue = malloc(sizeof(Node));
    queue->value = -1;
    queue->next = NULL;

    while (root->next != NULL)
    {
       root = root->next;
       if ((queue = push_back(queue, n, root->value)) == NULL)
           return -1;
    } 

    while (queue->next != NULL)
    {
        queue = queue->next;
        printf("%d, ", queue->value);
    }
    printf("\n");
    return 0;
}
