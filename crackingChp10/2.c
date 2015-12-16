/*
 *  Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    unsigned long value;
    struct Node *next;
}Node;

Node* newNode(unsigned long v)
{
    Node *node;
    
    if ((node = malloc(sizeof(Node))) == NULL)
        return NULL;

    node->value = v;
    node->next = NULL;
    return node;
}

Node* enqueue(Node* root, unsigned long v)
{
    if (root == NULL)
        return newNode(v);
    else if (root->next != NULL)
        root->next = enqueue(root->next, v);
    else
        root->next = newNode(v);
    return root;
}

Node* dequeue(Node* root, unsigned long *c)
{
    Node* tmp;
    if (root == NULL)
    {
        *c = -1;
        return NULL;
    }
    else
    {
        tmp = root->next;
        *c = root->value;
        free(root);
        return tmp;
    }
}
static Node* queue3 = NULL;
static Node* queue5 = NULL;
static Node* queue7 = NULL;

static Node* magic = NULL;


int main()
{
    int i, k;
    unsigned long c, c3, c5, c7;
    scanf("%d", &k);

    queue3 = enqueue(queue3, 3);
    queue5 = enqueue(queue5, 5);
    queue7 = enqueue(queue7, 7);

    magic = enqueue(magic, 1);

    for (--k; k > 0; k--)
    {
        c3 = queue3->value;
        c5 = queue5->value;
        c7 = queue7->value;

        c = (c3 < c5) ? c3 : (c5 < c7) ? c5 : c7;

        magic = enqueue(magic, c);
        if (c == c3)
        {
                queue3 = dequeue(queue3, &c3);
                queue3 = enqueue(queue3, (3 * c));
                queue5 = enqueue(queue5, (5 * c)); 
                queue7 = enqueue(queue7, (7 * c));
        }
        else if (c == c5)
        {
                queue5 = dequeue(queue5, &c5);
                queue5 = enqueue(queue5, (5 *c));
                queue7 = enqueue(queue7, (7 *c));
        }
        else
        {
                queue7 = dequeue(queue7, &c7);
                queue7 = enqueue(queue7, (7 *c));
        }
    }
        

    while(magic != NULL)
    {
        printf("%lu, ", magic->value);
        magic = magic->next;
    }
    printf("\n");
 
    return 0;
}

