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
    
    return node->height;
}

int getBalance(Node *node)
{
    if (NULL == node)
        return 0;
    return (height(node->left) - height(node->right));
}

Node* createNode(char v)
{
    Node *newNode = NULL;

    if ((newNode = malloc(sizeof(Node))) == NULL)
        return NULL;
    newNode->value = v;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node * y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    //rotation
    x->right = y;
    y->left = T2;

    //update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    //rotation
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, char val)
{
    int balance;

    if (NULL == root)
        return createNode(val);
    
    if (val < root->value)
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);

    root->height = max(height(root->left), height(root->right)) + 1;

    balance = getBalance(root);

    printf("%d\n", balance);

    //there could be 4 cases
    if (balance > 1 && val < root->left->value)
        return rightRotate(root);
    
    if (balance < -1 && val > root->right->value)
        return leftRotate(root);

    if (balance > 1 && val > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && val < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
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

void preOrder(Node *root)
{
    if (NULL != root)
    {
        printf("%c, ", root->value);
        preOrder(root->left);
        preOrder(root->right);
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
        tree = insert(tree, c++);

    if (NULL != tree)
        preOrder(tree);
    printf("\n");
    printf("LeftHeight: %d\n", height(tree->left));
    printf("RightHeight: %d\n", height(tree->right));
    
    return 0;
}
