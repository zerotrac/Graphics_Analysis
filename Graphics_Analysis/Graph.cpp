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
    assert(m == curM);
    
    return new EdgeList(1);
}

EdgeList* Graph::kruskal()
{
    assert(m == curM);
    
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
    
    assert(cnt == curM);
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
    return result;
}

int Graph::findset(int *fa, int x)
{
    if (fa[x] != x) fa[x] = findset(fa, fa[x]);
    return fa[x];
}

void Graph::uni(int *fa, int x, int y)
{
    assert(x != y);
    if (x > y) fa[x] = y; else fa[y] = x;
}
