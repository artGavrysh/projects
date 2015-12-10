/*
 *  Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth 
 *  (i.e., if you have a tree with depth D, you’ll have D linked lists).
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char value;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(Node* node)
{
    if (NULL == node)
        return 0;

    return node->height;
}

Node* rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    //rotate
    x->right = y;
    y->left = T2;

    //update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(y->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x)
{
   Node *y = x->right;
   Node *T2 = y->left;

   //rotate
   y->left = x;
   x->right = T2;

   x->height = max(height(x->left), height(x->right)) + 1;
   y->height = max(height(y->left), height(y->right)) + 1;

   return y;
}

int getBalance(Node* node)
{
    if (NULL == node)
        return 0;

    return (height(node->left) - height(node->right));
}

Node* newNode(char v)
{
    Node* node = NULL;

    if ((node = malloc(sizeof(Node))) == NULL)
        return NULL;
    node->value = v;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node * insert(Node* root, char v)
{
    int balance;

    if (NULL == root)
        return newNode(v);
    
    if (v < root->value)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);
    
    root->height = max(height(root->left), height(root->right)) + 1;

    balance = getBalance(root);

    if (balance > 1 && v < root->left->value)
        return rotateRight(root);

    if (balance < -1 && v > root->right->value)
        return rotateLeft(root);

    if (balance > 1 && v > root->left->value)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && v < root->right->value)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrder(Node *root)
{
    if (NULL != root->left)
        inOrder(root->left);
    printf("%c, ", root->value);
    if (NULL != root->right)
        inOrder(root->right);
}

typedef struct Elem
{
    char value;
    struct Elem *next;
}Elem;

Elem* newElem(char v)
{
    Elem* elem;
    
    if ((elem = malloc(sizeof(Elem))) == NULL)
        return NULL;
    elem->value = v;
    elem->next = NULL;
    return elem;
}

Elem* append(Elem *elem, char v)
{
    Elem* it;
    if (NULL == elem)
        return newElem(v);
    
    it = elem;
    while(elem != NULL)
    {
        printf("%c, ", elem->value);
        elem = elem->next;
    }
    printf("\n");
   
    elem = newElem(v);
    
    return it;
}

void postOrderList(Node *root, Elem **lists)
{
    if (NULL != root->left)
       postOrderList(root->left, lists); 
    if (NULL != root->right)
       postOrderList(root->right, lists);
    lists[root->height] = append(lists[root->height], root->value);
}

int main()
{
    int i;
    char c = 'a';
    Node *tree = NULL;
    Elem **lists = NULL;

    while (c <= 'z')
        tree = insert(tree, c++);
/*
    if (NULL != tree)
        inOrder(tree);
    printf("\n");
*/
    printf("The tree balance: %d <-> %d\n", height(tree->left), height(tree->right));
    
    if ((lists = malloc((height(tree) + 1) * sizeof(Elem*))) == NULL)
        return -1;

    // now buid the list elements
    postOrderList(tree, lists);
    //check it out
    for (i = 0; i < height(tree)+1; ++i)
    {
        while(lists[i] != NULL)
        {
            printf("%c -> ", (lists[i])->value);
            lists[i] = (lists[i])->next;
        }
        printf("\n");
    }
    
    return 0;
}
