//
//  Graph.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

// 图类
// 用邻接表存储

class Graph
{
private:
    int n; // 节点数
    int m; // 边数
    int curM; // 当前边数
    
    // 邻接表要用到的数组
    int* head;
    int* edge;
    int* value;
    int* next;
    
public:
    Graph(int _n, int _m);
    ~Graph();
    
public:
    void addEdge(int x, int y, int z); // 添加x->y，权值为z的边
    
public:
    
    
};

#endif
