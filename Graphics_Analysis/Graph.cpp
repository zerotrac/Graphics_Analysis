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
        dist[i] = INF;
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
    int* prev = new int[n];
    bool* used = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
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
    delete[] prev;
    delete[] used;
    
    return result;
}

EdgeList* Graph::spfa(int s, int t)
{
    std::queue<int> q;
    double* dist = new double[n];
    int* prev = new int[n];
    bool* used = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
        prev[i] = -1;
        used[i] = false;
    }
    dist[s] = 0;
    used[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            double w = value[i];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
                if (!used[v])
                {
                    q.push(v);
                    used[v] = true;
                }
            }
        }
        used[u] = false;
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
    delete[] prev;
    delete[] used;
    
    return result;
}

EdgeList* Graph::kpath(int s, int t, int kth)
{
    std::priority_queue<Tuple2> q;
    double* dist = new double[n];
    int* prev = new int[n];
    bool* used = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
        used[i] = false;
        prev[i] = -1;
    }
    dist[t] = 0.0;
    q.push(Tuple2(t, dist[t]));
    
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
    
    std::priority_queue<Tuple2New> q2;
    std::vector<Tuple2New> vec;
    q2.push(Tuple2New(s, dist[s], 0, -1));
    vec.push_back(Tuple2New(s, dist[s], 0, -1));
    
    int lcnt = 0;
    int curk = 0;
    
    EdgeList* result;
    while (!q2.empty())
    {
        Tuple2New cur = q2.top();
        int u = cur.x;
        double w = cur.y;
        q2.pop();
        if (u == t)
        {
            ++curk;
            if (curk == kth)
            {
                
                int edgesCount = 0;
                int curLabel = cur.label;
                while (curLabel != 0)
                {
                    ++edgesCount;
                    curLabel = vec[curLabel].fa;
                }
                result = new EdgeList(edgesCount);
                build2(result, cur.label, dist, vec);
                break;
            }
        }
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            double ww = value[i];
            q2.push(Tuple2New(v, w + ww + dist[v] - dist[u], ++lcnt, cur.label));
            vec.push_back(Tuple2New(v, w + ww + dist[v] - dist[u], lcnt, cur.label));
        }
    }
    
    delete[] dist;
    delete[] prev;
    delete[] used;
    
    return result;
}

NodeDoubleList* Graph::betweenness()
{
    double* cb = new double[n]; // CB[v]
    for (int i = 0; i < n; ++i)
    {
        cb[i] = 0.0;
    }
    
    double** dist = new double*[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = new double[n];
        for (int j = 0; j < n; ++j)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0.0;
    }
    for (int u = 0; u < n; ++u)
    {
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            if (value[i] < dist[u][v]) dist[u][v] = value[i];
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    double* sigma = new double[n];
    bool* used = new bool[n];
    int* order = new int[n];
    double* sum = new double[n];
    
    std::vector<std::vector<int>> pt(n);
    std::vector<std::vector<double>> val(n);
    for (int u = 0; u < n; ++u)
    {
        for (int j = head[u]; j != -1; j = next[j])
        {
            int v = edge[j];
            double w = value[j];
            pt[u].push_back(v);
            val[u].push_back(w);
        }
    }
    
    for (int s = 0; s < n; ++s)
    {
        std::vector<std::vector<int>> p(n);
        std::priority_queue<Tuple2> q;
        
        for (int i = 0; i < n; ++i)
        {
            sigma[i] = 0.0;
            used[i] = false;
            sum[i] = 0.0;
        }
        sigma[s] = 1.0;
        
        int od = 0;
        for (int i = 0; i < n; ++i)
        {
            int sel = 0;
            for (int j = 1; j < n; ++j)
            {
                if (!used[j])
                {
                    if (used[sel] || dist[s][j] < dist[s][sel]) sel = j;
                }
            }
            order[od++] = sel;
            used[sel] = true;
        }
        
        for (int i = 0; i < od; ++i)
        {
            int u = order[i];
            for (int j = 0; j < pt[u].size(); ++j)
            {
                int v = pt[u][j];
                double w = val[u][j];
                if (std::fabs(dist[s][v] - dist[s][u] - w) < 1e-6)
                {
                    sigma[v] += sigma[u];
                    p[v].push_back(u);
                }
            }
        }
        for (int i = od - 1; i >= 0; --i)
        {
            int u = order[i];
            for (int v: p[u])
            {
                sum[v] += (sigma[v] / sigma[u]) * (1.0 + sum[u]);
            }
            if (u != s)
            {
                cb[u] += sum[u] / 2.0;
            }
        }
    }
    
    NodeDoubleList* nodelist = new NodeDoubleList(n);
    for (int i = 0; i < n; ++i)
    {
        nodelist->setValue(i, cb[i]);
    }

    for (int i = 0; i < n; ++i) delete[] dist[i];
    delete[] dist;
    
    delete[] sigma;
    delete[] used;
    delete[] order;
    delete[] sum;
    delete[] cb;
    
    return nodelist;
}

NodeDoubleList* Graph::closeness()
{
    double** dist = new double*[n];
    for (int i = 0; i < n; ++i)
    {
        dist[i] = new double[n];
        for (int j = 0; j < n; ++j)
        {
            dist[i][j] = INF;
        }
        dist[i][i] = 0.0;
    }
    for (int u = 0; u < n; ++u)
    {
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            if (value[i] < dist[u][v]) dist[u][v] = value[i];
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    NodeDoubleList* nodelist = new NodeDoubleList(n);
    for (int i = 0; i < n; ++i)
    {
        double sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += dist[i][j];
        }
        nodelist->setValue(i, sum);
    }
    
    for (int i = 0; i < n; ++i) delete[] dist[i];
    delete[] dist;
    
    return nodelist;
}

ConnectList* Graph::component(int movieRelation, double scoreRelation)
{
    std::vector<Tuple3> edges;
    bool* used = new bool[n];
    int* group = new int[n];
    int compCount = 0;
    
    for (int i = 0; i < n; ++i)
    {
        used[i] = false;
        group[i] = -1;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            bfs(i, ++compCount, used, group, edges, movieRelation, scoreRelation);
        }
    }
    
    ConnectList* result = new ConnectList(n, (int)edges.size());
    result->setConnection(compCount);
    for (int i = 0; i < n; ++i) result->setValue(i, group[i]);
    for (Tuple3 elem: edges) result->addEdge(elem.x, elem.y, elem.z);
    
    delete[] used;
    delete[] group;
    
    return result;
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
    result->addEdge(prev[curNode], curNode, dist[curNode] - dist[prev[curNode]]);
}

void Graph::build2(EdgeList* result, int curLabel, const double* dist, const std::vector<Tuple2New>& v)
{
    if (v[curLabel].fa != -1) build2(result, v[curLabel].fa, dist, v); else return;
    double value = (v[curLabel].y - v[v[curLabel].fa].y) - (dist[v[curLabel].x] - dist[v[v[curLabel].fa].x]);
    result->addEdge(v[v[curLabel].fa].x, v[curLabel].x, value);
}

void Graph::bfs(int node, int compCount, bool *used, int *group, std::vector<Tuple3> &edges, int movieRelation, double scoreRelation)
{
    std::queue<int> q;
    q.push(node);
    used[node] = true;
    group[node] = compCount;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int i = head[u]; i != -1; i = next[i])
        {
            int v = edge[i];
            if (!used[v])
            {
                double w = value[i];
                int p1 = (int)w;
                double p2 = w - p1;
                if (p1 >= movieRelation && p2 + 1e-7 >= scoreRelation)
                {
                    q.push(v);
                    used[v] = true;
                    group[v] = compCount;
                    edges.push_back(Tuple3(u, v, w));
                }
            }
        }
    }
}
