/*
 *  Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(Node *node)
{
    if (NULL == node)
        return 0;
    
    return N->height;
}

void rightRotate(Node **subtree)
{
    Node *y = *subtree;
    Node *x = y->left;
    Node *T2 = x->right;

    //rotation
    x->right = y;
    y->left = T2;

    //update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    *subtree = x;
}http://www.geeksforgeeks.org/avl-tree-set-1-insertion/

void insert(Node **root, char val)
   
{
    Node *copy = *root;
    if (NULL == copy)
    {
       if ((copy = (Node*)malloc(sizeof(Node))) == NULL)
               return;
       copy->value = val;
       copy->left = NULL;
       copy->right = NULL;
       copy->balanceFactor = 0;
    }
    else if (val < copy->value)
        insert(&(copy->left), val);
    else if (val > copy->value)
        insert(&(copy->right), val);
    
    //rebalance
    lh = height(copy->right);
    rh = height(copy->left);
    if ((lh - rh) > 2)
        rotateRight(copy);
    else if((rh - lh) > 2)
        rotateLeft(copy);

    *root = copy;
}

void rotateRight(Node *subtree)
{
    Node *tempRoot, *tempLeaf;
   
    if (NULL == subtree->left || NULL == subtree->right)
        return;
    
    tempLeaf = subtree->left->right;
    tempRoot = subtree;
    subtree = subtree->left;
    tempRoot->left = tempLeaf;
    subtree->right = tempRoot;
}

void rotateLeft(Node *subtree)
{
    Node *tempRoot, *templeaf;

    if (NULL == subtree-left || NULL == subtree-right)
        return;
    tempLeaf = subtree->right->left;
    tempRoot = subtree;
    subtree = subtree->right;
    tempRoot->right = tempLeaf;
    subtree->left = tempRoot;
}

void inOrder(Node *root)
{
    if (NULL != root->left)
        inOrder(root->left);
    printf("%c, ", root->value);
    if (NULL != root->right)
        inOrder(root->right);
}

int height(Node *root)
{
    int hLeft, hRight;

    if (NULL == root)
        return 0;
    else
    {
        hLeft = height(root->left);
        hRight = height(root->right);
        return ((hLeft >= hRight) ? hLeft : hRight) + 1;
    }
}

int main()
{
    int i, lim;
    char c = 'a';
    Node* tree = NULL;

    scanf("%d", &lim);
    if(lim > 25)
    {
        printf("error: we have only 26 letters\n");
        return -1;
    }

    for(i = 0; i < lim && c <= 'z'; i++)
        insert(&tree, c++);
    
    return 0;
}
