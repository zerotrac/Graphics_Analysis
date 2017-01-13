//
//  EdgeList.hpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef EDGELIST_H
#define EDGELIST_H

#include <iostream>
#include <fstream>

// 边集合类
// 作用是作为一些图类的成员函数的返回值
// 全public

class EdgeList
{
public:
    int m; // 边数
    int curM; // 当前边数
    
    // 在最短路（k短路）中，value表示最短路的长度
    // 在最小生成树中，value表示最小生成树的边权之和
    // 反正都是边权之和啦
    double value;
    
    // x, y, z数组表示起点，终点，权值
    int* x;
    int* y;
    double* z;
    
public:
    EdgeList(int _m);
    ~EdgeList();
    
public:
    void addEdge(int _x, int _y, double _z);
    void print(std::ofstream& out);
};

#endif
