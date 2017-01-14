//
//  ConnectList.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/14.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef CONNECTLIST_H
#define CONNECTLIST_H

#include "EdgeList.h"
#include "NodeList.h"

// 联通分量集合类
// NodeList* 用来存储每个点所在的联通分量编号
// EdgeList* 用来存储同一个联通分量关联的边

class ConnectList
{
public:
    NodeIntList* nodelist;
    EdgeList* edgelist;
    int connectionCount;
    
public:
    ConnectList(int _n, int _m);
    ~ConnectList();
    
public:
    void setValue(int x, int _value);
    void addEdge(int _x, int _y, double _z);
    void setConnection(int _count);
    void print(std::ofstream& out);
    
};

#endif
