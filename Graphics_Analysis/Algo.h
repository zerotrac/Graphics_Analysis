//
//  Algo.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/13.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <set>
#include "Tuple3.h"

// 这里面是一些静态函数
// 用来处理数据的（前期处理）
// 比如说删除数据里面的孤立节点之类的

class Algo
{
public:
    static void discrete()
    {
        std::ifstream in("data.txt");
        std::ofstream out("data_new.txt");
        int n, m;
        in >> n >> m;
        Tuple3* edges = new Tuple3[m];
        std::set<int> s;
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            double z;
            in >> x >> y >> z;
            edges[i] = Tuple3(x, y, z);
            s.insert(x);
            s.insert(y);
        }
        int* ref = new int[n];
        int cnt = 0;
        for (int elem: s) ref[elem] = cnt++;
        
        out << s.size() << " " << m << std::endl;
        out << std::fixed << std::setprecision(3);
        for (int i = 0; i < m; ++i)
        {
            out << ref[edges[i].x] << " " << ref[edges[i].y] << " " << edges[i].z << std::endl;
        }
        
        delete[] edges;
        delete[] ref;
    }
    
    static void randomGraph()
    {
        std::ofstream out("data_new.txt");
        int n = 20;
        int m = n * (n - 1) / 2;
        out << n << " " << m << std::endl;
        srand((unsigned)time(nullptr));
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                out << i << " " << j << " " << rand() % 100 + 1 << std::endl;
            }
        }
    }
};

#endif
