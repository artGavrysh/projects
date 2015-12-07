/*
 *  Implement a function to check if a tree is balanced. 
 *  For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes 
 *  differ in distance from the root by more than one.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char value;
    struct Node* left;
    struct Node* right;
} Node;

//this should be recursive
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
    }
    else if (val < copy->value)
        insert(&(copy->left), val);
    else if (val > copy->value)
        insert(&(copy->right), val);

    *root = copy;
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

int abs(int v)
{
    return (v >= 0) ? v : -v;
}  

char isBalanced(Node* root)
{
    int hLeft, hRight;
    if(NULL == root)
        return 1;
    else
    {
        hLeft = height(root->left);
        hRight = height(root->right);
        printf("%d <-> %d\n", hLeft, hRight);
        if (abs(hLeft - hRight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return 1;
        else
            return 0;
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
    
    if (NULL != tree)
    {
        if (isBalanced(tree))
            printf("Balanced");
        else
            printf("Not balanced");
    }
    else
    {
        printf("first tree is null");
        //return -1;
    }
    printf("\n");
    //this is to build a balanced tree
    tree = NULL;

    insert(&tree, 'c');
    insert(&tree, 'a');
    insert(&tree, 'b');
    insert(&tree, 'd');
    insert(&tree, 'e');
    
    if (NULL != tree)
    {
        if (isBalanced(tree))
            printf("Balanced");
        else
            printf("Not balanced");
    }
    else
    {
        printf("second tree is null");
        return -1;
    }
    printf("\n");

    return 0;
}
