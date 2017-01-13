//
//  NodeList.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/13.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "NodeList.h"

NodeIntList::NodeIntList(int _n)
{
    n = _n;
    values = new int[n];
    for (int i = 0; i < n; ++i) values[i] = 0;
}

NodeIntList::~NodeIntList()
{
    delete[] values;
}

void NodeIntList::setValue(int x, int _value)
{
    values[x] = _value;
}

void NodeIntList::print(std::ofstream &out)
{
    out << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        out << values[i] << std::endl;
    }
}

NodeDoubleList::NodeDoubleList(int _n)
{
    n = _n;
    values = new double[n];
    for (int i = 0; i < n; ++i) values[i] = 0.0;
}

NodeDoubleList::~NodeDoubleList()
{
    delete[] values;
}

void NodeDoubleList::setValue(int x, double _value)
{
    values[x] = _value;
}

void NodeDoubleList::print(std::ofstream &out)
{
    out << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        out << values[i] << std::endl;
    }
}
