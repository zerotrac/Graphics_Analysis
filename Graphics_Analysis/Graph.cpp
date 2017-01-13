//
//  Graph.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "Graph.h"

Graph::Graph(int _n, int _m)
{
    n = _n;
    m = _m;
    curM = 0;
    
    head = new int[n];
    edge = new int[m];
    value = new double[m];
    next = new int[m];
    
    for (int i = 0; i < n; ++i)
    {
        head[i] = -1;
    }
}

Graph::~Graph()
{
    delete[] head;
    delete[] edge;
    delete[] value;
    delete[] next;
}

void Graph::addEdge(int x, int y, double z)
{
    edge[curM] = y;
    value[curM] = z;
    next[curM] = head[x];
    head[x] = curM;
    ++curM;
}

EdgeList* Graph::prim()
{
    std::priority_queue<Tuple2> q;
    double* dist = new double[n];
    bool* used = new bool[n];
    int* prev = new int[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INFINITY;
        used[i] = false;
        prev[i] = -1;
    }
    dist[0] = 0.0;
    q.push(Tuple2(0, dist[0]));
    EdgeList* result = new EdgeList(n - 1);
    
    while (!q.empty())
    {
        Tuple2 cur = q.top();
        int u = cur.x;
        q.pop();
        if (used[u]) continue;
        used[u] = true;
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            double ww = value[i];
            if (!used[v] && ww < dist[v])
            {
                dist[v] = ww;
                prev[v] = u;
                q.push(Tuple2(v, dist[v]));
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (prev[i] != -1)
        {
            result->addEdge(i, prev[i], dist[i]);
        }
    }
    
    delete[] dist;
    delete[] used;
    delete[] prev;
    
    return result;
}

EdgeList* Graph::kruskal()
{
    Tuple3* edges = new Tuple3[m];
    int cnt = 0;
    for (int u = 0; u < n; ++u)
    {
        for (int j = head[u]; j != -1; j = next[j])
        {
            int v = edge[j];
            double w = value[j];
            edges[cnt++] = Tuple3(u, v, w);
        }
    }
    
    std::sort(edges, edges + m);
    
    EdgeList* result = new EdgeList(n - 1);
    int* fa = new int[n];
    for (int i = 0; i < n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i)
    {
        int x = edges[i].x;
        int y = edges[i].y;
        double z = edges[i].z;
        int fx = findset(fa, x);
        int fy = findset(fa, y);
        if (fx != fy)
        {
            result->addEdge(x, y, z);
            uni(fa, fx, fy);
        }
    }
    
    delete[] edges;
    delete[] fa;
    
    return result;
}

EdgeList* Graph::dijkstra(int s, int t)
{
    std::priority_queue<Tuple2> q;
    double* dist = new double[n];
    bool* used = new bool[n];
    int* prev = new int[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INFINITY;
        used[i] = false;
        prev[i] = -1;
    }
    dist[s] = 0.0;
    q.push(Tuple2(s, dist[s]));
    
    while (!q.empty())
    {
        Tuple2 cur = q.top();
        int u = cur.x;
        double w = cur.y;
        q.pop();
        if (used[u]) continue;
        used[u] = true;
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            double ww = w + value[i];
            if (!used[v] && ww < dist[v])
            {
                dist[v] = ww;
                prev[v] = u;
                q.push(Tuple2(v, dist[v]));
            }
        }
    }
    int edgesCount = 0;
    int curNode = t;
    while (curNode != s)
    {
        ++edgesCount;
        curNode = prev[curNode];
    }
    EdgeList* result = new EdgeList(edgesCount);
    build(result, dist, prev, t);
    
    delete[] dist;
    delete[] used;
    delete[] prev;
    
    return result;
}

EdgeList* Graph::spfa(int s, int t)
{
    std::queue<int> q;
    double* dist = new double[n];
    int* prev = new int[n];
    bool
    
    return new EdgeList(0);
}

int Graph::findset(int *fa, int x)
{
    if (fa[x] != x) fa[x] = findset(fa, fa[x]);
    return fa[x];
}

void Graph::uni(int *fa, int x, int y)
{
    if (x > y) fa[x] = y; else fa[y] = x;
}

void Graph::build(EdgeList* result, const double* dist, const int* prev, int curNode)
{
    if (prev[curNode] != -1) build(result, dist, prev, prev[curNode]); else return;
    std::cout << "x, y = " << prev[curNode] << " " << curNode << std::endl;
    result->addEdge(prev[curNode], curNode, dist[curNode] - dist[prev[curNode]]);
}
