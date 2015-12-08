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
    int depth;
}Node;

int max(int a, int b)
{
    return (a <= b) ? a : b;
}

int height(Node* node)
{
    if(NULL == node)
        return 0;

    return (height(node->left), height(node->rigth)) + 1;
}

Node* rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    //rotate
    x->right = y;
    y->left = T2

    //update height
    y->depth = max(height(y->left), height(y->right)) + 1;
    x->depth = max(height(x->left), height(y->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x)
{
   Node *y = x->right;
   Node *T2 = x->left;

   //rotate
   y->left = x;
   x->right = T2;

   x->depth = max(height(x->left), height(x->right)) + 1;
   y->depth = max(height(y->left), height(y->right)) + 1;

   return y;
}

int getBalance(Node* node)
{
    if (NULL == node)
        return 0;

    return (height(node->left) - height(node->right));
}
    

Node * insert(Node* root, char v)
{
    if (NULL == root)
        return newNode(v);

    if (v < root->value)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);

    balance = getBalance(root);

    if (balanse < -1 && v < root->left->value)
        return rotateRight(root);

    if (balance > 1 && v > root->right->value)
        return rotateLeft(root);

    if (balance < -1 && v > root->left->value)
    {
        rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance > 1 && v < root->right->value)
    {
        rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
