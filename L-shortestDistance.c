/*
 * given the weighted non-oriented graph find the shortest distance from one Node 1 to Node N and return it's distance
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 10000
#define INF      1000000000000000

typedef struct Node
{
    int id;
    int arc;
    struct Node *next;
} Node;

Node* newNode(int id, int length)
{
    Node *nNode = NULL;
    if ((nNode = malloc(sizeof(Node))) == NULL )    
        return NULL;
    nNode->id = id;
    nNode->arc = length;
    nNode->next = NULL;
    return nNode;
}

Node *put(Node* root, int id, int length)
{
    if (root == NULL)
        return newNode(id, length);
    else if (root->next == NULL)
        root->next = newNode(id, length);
    else
        root->next = put(root->next, id, length);
    return root;
} 

void *get(Node* root)
{
    while(root != NULL)
    {
        printf("%d, ", root->id+1);
        root = root->next;
    }
}

/*
 *   heap: has container and two methods push and pop with underlying methods bubleUp and bubleDown
 */
typedef struct HeapElem
{
    Node *node;
    long long path;
}HeapElem; 

typedef struct Heap
{
    HeapElem *m_store[MAX_NODE];
    int m_size;
}Heap;

HeapElem *newElem(Node* node, long long path)
{
    HeapElem *hElem = NULL;
    if ((hElem = malloc(sizeof(HeapElem))) == NULL)
        return NULL;
    hElem->node = node;
    hElem->path = path;
    return hElem;
}       

void swap(Heap* heap, int i, int j)
{
    HeapElem *temp = heap->m_store[i];
    heap->m_store[i] = heap->m_store[j];
    heap->m_store[j] = temp;
}

void bubleUp(Heap* heap, int idx)
{
    int parentIdx;
 
    if (0 == idx)
        return;
    
    parentIdx = ((idx + 1) / 2) - 1;
    if (heap->m_store[parentIdx]->path > heap->m_store[idx]->path)
    {
         swap(heap, parentIdx, idx);
         bubleUp(heap, parentIdx);
    }   
    else
         return;
}

void push(Heap* heap, Node *node, int pathLen)
{
    HeapElem *nElem = NULL;
    if ((nElem = newElem(node, pathLen)) != NULL)
    {
        heap->m_store[heap->m_size] = nElem;
        bubleUp(heap, heap->m_size);
        heap->m_size++;
    }
}

void bubleDown(Heap* heap, int idx)
{
    int childA = idx * 2 + 1;
    int childB = idx * 2 + 2;

    if (childA >= heap->m_size)
        return;
    else if ((childB >= heap->m_size) || (heap->m_store[childA]->path < heap->m_store[childB]->path))
    {
        if (heap->m_store[idx]->path > heap->m_store[childA]->path)
        {
            swap(heap, idx, childA);
            bubleDown(heap, childA);
        }
    }
    else
    {
        if (heap->m_store[idx]->path > heap->m_store[childB]->path)
        {
            swap(heap, idx, childB);
            bubleDown(heap, childB);
        }
    }
}   

HeapElem *pop(Heap* heap)
{
    HeapElem *temp = heap->m_store[0];
    heap->m_size--;
    heap->m_store[0] = heap->m_store[heap->m_size];
    bubleDown(heap, 0);
    return temp;
}

static char used[MAX_NODE];
static long long dist[MAX_NODE];
static Node *adjacency[MAX_NODE];
static Heap heap; 

long long dijkstra(int from, int to);

int main()
{
    int N, M, a, b, c, i;

    scanf("%d %d", &N, &M);
    
    adjacency[0] = put(adjacency[0], 0, 0); //this is for initialization
    
    for (i = 0; i < M; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        
        a--;
        b--;
        
        adjacency[a] = put(adjacency[a], b, c);
        adjacency[b] = put(adjacency[b], a, c);
    }
    
    printf("%lld\n", dijkstra(0, --N));
    return 0;
}

long long dijkstra(int from, int to)
{
    int i;
    long long newPath;
    HeapElem *base = NULL;
    Node  *tmp = NULL;
    //initializaion
    for (i = 0; i < MAX_NODE; ++i)
    {
        used[i] = 0;
        dist[i] = INF;
    }
    dist[from] = 0;
    push(&heap, adjacency[0], 0);
    
    while (heap.m_size > 0 && 1 != used[to])
    {
        base = pop(&heap);
        printf("%d : ", base->node->id+1);
        used[base->node->id] = 1;
        tmp = adjacency[base->node->id];
        while (tmp != NULL)
        {
            printf("%d, ", tmp->id+1);
            if (0 == used[tmp->id])
            {
                newPath = base->path + tmp->arc;
                if (newPath < dist[tmp->id])
                {
                    dist[tmp->id] = newPath;
                    push(&heap, tmp, newPath);
                }
            }
            tmp = tmp->next;
        }
        printf("\n");
    }
    return dist[to];
}
