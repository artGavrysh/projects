/*
 * Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
 * EXAMPLE
 * Input: the node ‘c’ from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks like a->b->d->e
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

Node* getPointer(Node* root, int idx)
{
    int i = 0;
    while (root->next != NULL && i < idx)
    {
        root = root->next;
        ++i;
    }
    return root;
}

void deleteNode(Node* node)
{
    Node *tmp;

    if (node->next != NULL)
    {
        tmp = node->next;

        if (tmp->next != NULL)
        {
            node->value = tmp->value;
            node->next = tmp->next;
            free(tmp);
        }
        else
        {
            node->value = tmp->value;
            node->next = NULL;
            free(tmp);
        }
    }
}

int main()
{
    int len, idx;
    Node *root, *ptr;

    scanf("%d %d", &len, &idx);

    if (idx >= len)
    {
        printf("Error: it's not possible to delete the last element \n");
        printf("in a conventional linked list given only it's address\n");
        return -1;
    }

    root = populate(len);
    ptr = getPointer(root, idx);
    
    printf("%d\n", ptr->value);
    deleteNode(ptr);

    while(root->next != NULL)
    {
        root = root->next;
        printf("%d, ", root->value);
    }
    printf("\n");
    
    return 0;
}

