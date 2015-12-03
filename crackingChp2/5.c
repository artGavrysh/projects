/*
 * Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, 
 * so as to make a loop in the linked list.
 * EXAMPLE
 * input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * output: C
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

Node* makeCircular(Node* root, int idx)
{
    int i = 0;
    Node* holder = root;
    Node* cp = root;
    
    while(cp->next != NULL)
        cp = cp->next;

    while (root->next != NULL && i < idx)
    {
        root = root->next;
        ++i;
    }
    cp->next = root;

    return holder;
}
//this it not absolutely correct: it only return true or false if there is a circularity. it does not return
//the circularity entering point
Node* findCircular(Node* root)
{
    Node *slower = root, *faster = root->next;

    while(1)
    {
        if (faster == NULL || faster->next == NULL)
            return NULL;
        else if (faster == slower || faster->next == slower)
            return slower;
        else
        {
            slower = slower->next;
            faster = faster->next->next;
        }
    }
}

int main()
{
    int len, idx;
    Node *root, *slower, *circular = NULL;
    
    scanf("%d %d", &len, &idx);

    root = populate(len);
    root = makeCircular(root, idx);
    
    

    if ((circular = findCircular(root)) != NULL)
        printf("%d\n", circular->value);
    else
        printf("Nothing found\n");

    
    return 0;
}

