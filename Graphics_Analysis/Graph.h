//
//  Graph.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include "ConnectList.h"
#include "Tuple2.h"
#include "Tuple2New.h"
#include "Tuple3.h"

// 图类
// 用邻接表存储

class Graph
{
private:
    static const double INF;
    
private:
    int n; // 节点数
    int m; // 边数
    int curM; // 当前边数
    
    // 邻接表要用到的数组
    int* head;
    int* edge;
    double* value;
    int* next;
    
public:
    Graph(int _n, int _m);
    ~Graph();
    
public:
    void addEdge(int x, int y, double z); // 添加x->y，权值为z的边
    
    // 最小生成树算法
    EdgeList* prim(); // O(nlogn + m)
    EdgeList* kruskal(); // O(mlogm)
    
    // 最短路算法
    EdgeList* spfa(int s, int t); // O(km), k的期望大约为2
    EdgeList* dijkstra(int s, int t); // O(nlogn + m)
    EdgeList* kpath(int s, int t, int kth); // O(nlogn + m + kn)
    
    // 中心度算法
    NodeDoubleList* betweenness(); // O(nlogn + mn)
    NodeDoubleList* closeness(); // O(n^3)
    
    // 连通度算法
    ConnectList* component(int movieRelation, double scoreRelation);
    
private:
    // 算法辅助函数
    int findset(int* fa, int x);
    void uni(int* fa, int x, int y);
    void build(EdgeList* result, const double* dist, const int* prev, int curNode);
    void build2(EdgeList* result, int curLabel, const double* dist, const std::vector<Tuple2New>& v);
    void bfs(int node, int compCount, bool* used, int* group, std::vector<Tuple3>& edges, int movieRelation, double scoreRelation);
};

#endif
