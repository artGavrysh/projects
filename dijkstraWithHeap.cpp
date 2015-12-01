#include <stdio.h>
4 5
1 2 10
1 3 30
2 3 5
2 4 30
3 4 10
25

5 7
1 2 3
2 3 4
3 5 4
1 4 4
4 5 5
2 4 2
3 4 2

9
/* find the shortest path in a graph 
 * represent a graph as adjacency set
 * represent a search as a priority gueue - heap
 */

#define MAX_N 1000000

struct Node
{
    int other;
    int dist;

    Node() {}

    Node(int a, int b)
    {
        this->other = a;
        this->dist = b;
    }
};

struct HeapElem 
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
};

template <typename T>
void swap(int *v, int i, int j)
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

struct NodeInfo
{
    bool visited;
    long long pathLen;
}


static Vector<Node> adjacency[MAX_N];
static Heap<HeapElem> heap;
static NodeInfo info[MAX_N];

int dijkstra(int N, int source, int sink)
{
    int i;
    for (i = 0; i < N; ++i)
    {
        info[i].visited = false;
        info[i].pathLen = INF;
    }
    
    heap.push(HeapElem(source, 0));
    while (heap.size() > 0)
    {
        HeapElem base = heap.pop();
        visited[base.node] = true;

        for (i = 0; i < adjacency[base.node].size(); ++i)
        {
            Node neighbour = adjacency[base.node][i];
            if (!info[neighbour.other])
            {
                long long newDist = base.absDist + neighbour.dist;
                if (other.dist > newDist)
                {
                   other.dist = newDist;
                   other.parent = base;
                   heap.push(HeapElem(other, newDist));
                }
            }
        }
    }
    return 0;
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

        adjacency[u].push(v, w);
        adjacency[v].push(u, w);
    }

    return 0;
}
