//
//  NodeList.hpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/13.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef NODELIST_H
#define NODELIST_H

#include <iostream>
#include <fstream>

// 点集合类
// 用来存中心度，联通分量之类的东西

class NodeIntList
{
public:
    int n; // 点数
    int* values; // 权值
    
    NodeIntList(int _n);
    ~NodeIntList();
    
public:
    void setValue(int x, int _value);
    void print(std::ofstream& out);
};

class NodeDoubleList
{
public:
    int n;
    double* values;
    
    NodeDoubleList(int _n);
    ~NodeDoubleList();
    
public:
    void setValue(int x, double _value);
    void print(std::ofstream& out);
};

#endif
