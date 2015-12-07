/*
 *  Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct Elem
{
    int value;
    struct Elem *next;
} Elem;

int append (Elem **root, int value)
{
    int i = 0;
    Elem *newNode, *copy = *root;
    if (NULL == copy)
    {
        copy = (Elem*)malloc(sizeof(Elem));
        copy->value = value;
        copy->next = NULL;
        *root = copy;
        return ++i;
    }
    
    while(copy->next != NULL)
    {
        copy = copy->next;
        ++i;
    }
    if ((newNode = (Elem*)malloc(sizeof(Elem))) == NULL)
        return -1;
    newNode->value = value;
    newNode->next = NULL;
    copy->next = newNode;
    *root = copy;
    return ++i;
}

static Elem* adjacency[MAX_N];
static char used[MAX_N];

char dfs(int source, int sink)
{
    char res = 0;
    used[source] = 1;
    while (adjacency[source] != NULL)
    {
        if(adjacency[source]->value == sink)
            res =  1;
        else
            if(!used[adjacency[source]->value])
                res = dfs(adjacency[source]->value, sink);
        adjacency[source] = adjacency[source]->next;
    }
    return  res;
}

int main()
{
    int N, K, A, B, i, a, b;
    Elem *copy;

    scanf("%d %d %d %d", &N, &K, &A, &B);
    A--;
    B--;
    
    for(i = 0; i < N; ++i)
        used[i] = 0;

    for(i = 0; i < K; ++i)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (a < b)
            append(&adjacency[a], b);
        else
            append(&adjacency[b], a);
    }
    if(dfs(A, B))
        printf("There is a path betwen \n");
    else
        printf("There is NO path between\n");

    return 0;
}
