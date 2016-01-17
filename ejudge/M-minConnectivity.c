/*
 *   Given an undirected graph find the min number of extra arcs to connect all nodes.
 * У вас есть N городов и K дорог, которые их соединяют. Нужно найти минимальное количество 
 * дорог, 
 * которые нужно еще построить, чтобы из любого города A всегда существовал маршрут в 
 * любой другой город B.
 * 10 10
 * 1 3 4 3 2 3 4 5 6 5 7 5 8 5 2 7 7 8 8 6
 */
#include <stdio.h>

/* I just need to find how many disjoint set the graph contains */
/* Count how many dfs we can get out of the graph */

#define N_MAX 10000

template <typename T>
class Vector
{
    T m_container[N_MAX];
    size_t m_size;
public: 
    Vector()
    {
        m_size = 0;
    }

    ~Vector(){}

    void push_back(T v)
    {
        m_container[m_size++] = v; 
    }

    void assign(size_t size, T v)
    {
        m_size = 0;
        while (m_size < size)
            m_container[m_size++] = v;
    }

    T operator[](size_t i)
    {
        if (i >= 0 && i < m_size)
            return m_container[i];
    }

    size_t size()
    {
        return m_size;
    }

};

static Vector<int> adjacency[N_MAX];
static char used[N_MAX];

void dfs(int v)
{
    int i, to;
    used[v] = 1;
    for(i = 0; i < adjacency[v].size(); ++i)
    {   
        to = adjacency[v][i];
        if(!used[to])
            dfs(to);
    }
}

int main()
{
    int N, M, a, b, i, counter = 0;
    scanf("%d %d", &N, &M);
    
    //used.assign(N, 0);

    for (i = 0; i < N; ++i)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;

        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }

    for (i = 0; i < N; ++i)
    {
        if (!used[i])
        {
            counter++;
            dfs(i);
        }
    }
    printf("%d\n", counter - 1);

    return 0;
}
