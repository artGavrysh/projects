/*
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */
#include <stdio.h>
#include <stdlib.h>

/* create an unsorted linked list */

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Node;

Node* addToList(Node *list, int newVal)
{
    Node *newNode, *copy = list;
    while (list->next != NULL)
        list = list->next;
    
    if ((newNode = (Node*)malloc(sizeof(Node))) == NULL)
        return NULL;

    newNode->value = newVal;
    newNode->next = NULL;

    list->next = newNode;

    return copy; 
}

int main()
{
    int i;
    Node *temp, *copyI, *copyJ, *root = malloc(sizeof(Node));
    root->next = NULL;

    //fill the list twice
    for (i = 0; i < 5; ++i)
    {
        if ((root = addToList(root, i)) == NULL)
        {
            printf("error when building\n");
            return -1;
        }
    }
   
    for (i = 0; i < 5; ++i)
    {
        if ((root = addToList(root, i)) == NULL)
        {
            printf("error when building\n");
            return -1;
        }
    }
   
    //remove the duplicates
    copyI = root;
    while(copyI->next != NULL)
    {
        copyI = copyI->next;
        copyJ = copyI;
        while (copyJ->next != NULL)
        {
            copyJ = copyJ->next;
            if (copyJ->next != NULL)
            {
                if (copyJ->next->value == copyI->value)
                {
                   temp = copyJ->next;
                   copyJ->next = copyJ->next->next;
                   free(temp);
                }
            }
        }
        if (copyI->next != NULL && copyI->next->value == copyI->value)
        {
            free(copyI->next);
            copyI->next = NULL;
        }
    } 
    //print the result
    printf("\n");
    while (root->next != NULL)
    {
        root = root->next;
        printf("%d, ", root->value);
    }
    printf("\n");

    return 0;
}

