#include <stdio.h>

/* find the shortest path in a graph 
 * represent a graph as adjacency set
 * represent a search as a priority gueue - heap
 */

#define MAX_N 1000000
#define INF   100000000

typedef struct Node
{
    int idx;
    int dist;

    Node() {}

    Node(int a, int b)
    {
        this->idx = a;
        this->dist = b;
    }
}Node;

typedef struct HeapElem 
{
    int node;
    long long absDist;

    HeapElem(){}

    HeapElem(int a, long long dist)
    {
        this->node = a;
        this->absDist = dist;
    }
    
    int operator<(const HeapElem &other)
    {
        return this->absDist < other.absDist;
    }
}HeapElem;

template <typename T>
void swap(T *v, int i, int j)
{
    T temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

template <typename T>
void siftUp(T *v, int idx)
{
    int childIdx;
    while (idx - 1 >= 0) //the same as the condition ((i-1) / 2)
    {
        childIdx = idx;
        idx = (idx - 1) / 2; // move up the heap
        if ( v[childIdx]  < v[idx]) //max heap: parent should be smaller
                swap<T>(v, idx, childIdx);
        else
            return;
    }
}

template <typename T>
void siftDown(T *v, int len, int idx)
{
    int parentIdx;
    while (idx * 2 + 1 < len)
    {
        parentIdx = idx;
        idx = idx * 2 + 1;
        if ( v[idx] < v[parentIdx])
            swap<T>(v, parentIdx, idx);
        else
            return;
     }
}

template <typename T>
class Heap
{
    private:
        T m_storage[MAX_N];
        int m_size;
    public:
        Heap()
        {
            m_size = 0;
        }

        void push(T v)
        {
            m_storage[m_size] = v;
            siftUp<T>(m_storage, m_size);
            m_size++;
        }

        T pop(void)
        {
            T res = m_storage[0];
            m_size--;
            m_storage[0] = m_storage[m_size];
            siftDown<T>(m_storage, m_size, 0);
            return res;
        }

        int size(void)
        {
            return m_size;
        }
};

template <typename T>
class Vector
{
    private:
        T m_storage[MAX_N];
        int m_size;
    public:
        Vector()
        {
            m_size = 0;
        }

        void push(T v)
        {
            m_storage[m_size++] = v;
        }

        T operator[](int i)
        {
            return m_storage[i];
        }
        
        int size(void)
        {
            return m_size;
        }
};

typedef struct NodeInfo
{
    bool visited;
    long long pathLen;
}NodeInfo;

static Vector<Node> adjacency[MAX_N];
static Heap<HeapElem> heap;
static NodeInfo info[MAX_N];

long long dijkstra(int N, int from, int to)
{
    int i;
    for (i = 0; i < N; ++i)
    {
        info[i].visited = false;
        info[i].pathLen = INF;
    }
    
    heap.push(HeapElem(from, 0));
    while (heap.size() > 0)
    {
        HeapElem current = heap.pop();
        info[current.node].visited = true;

        for (i = 0; i < adjacency[current.node].size(); ++i)
        {
            Node neighbour = adjacency[current.node][i];
            if (!info[neighbour.idx].visited)
            {
                long long newDist = current.absDist + neighbour.dist;
                if (info[neighbour.idx].pathLen > newDist)
                {
                   info[neighbour.idx].pathLen = newDist;
                   heap.push(HeapElem(neighbour.idx, newDist));
                }
            }
        }
    }
    return 0L;
}

int main()
{
    int i, N, M, u, v, w;
    
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        
        u--;
        v--;

        adjacency[u].push(Node(v, w));
        adjacency[v].push(Node(u, w));
    }
    long long dist = dijkstra(N, 0, N-1);
    
    printf("%lld\n", dist);

    return 0;
}
