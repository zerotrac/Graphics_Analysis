//
//  Graph.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <algorithm>
#include <queue>
#include "EdgeList.h"
#include "Tuple2.h"
#include "Tuple3.h"

// 图类
// 用邻接表存储

class Graph
{
private:
    constexpr static double INFINITY = 999999999.0;
    
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
    EdgeList* prim(); // O((nlogn + m)
    EdgeList* kruskal(); // O(mlogm)
    
private:
    // kruskal算法辅助函数（并查集）
    int findset(int* fa, int x);
    void uni(int* fa, int x, int y);
};

#endif
