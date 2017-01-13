//
//  EdgeList.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "EdgeList.h"

EdgeList::EdgeList(int _m)
{
    m = _m;
    curM = 0;
    value = 0.0;
    
    x = new int[m];
    y = new int[m];
    z = new double[m];
}

EdgeList::~EdgeList()
{
    delete[] x;
    delete[] y;
    delete[] z;
}

void EdgeList::addEdge(int _x, int _y, double _z)
{
    if (curM >= m) return;
    x[curM] = _x;
    y[curM] = _y;
    z[curM] = _z;
    value += _z;
    ++curM;
}

void EdgeList::print(std::ofstream& out)
{
    out << m << std::endl;
    for (int i = 0; i < m; ++i)
    {
        out << x[i] << " " << y[i] << " " << z[i] << std::endl;
    }
    out << value << std::endl;
}
