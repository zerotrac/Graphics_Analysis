//
//  ConnectList.cpp
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/14.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#include "ConnectList.h"

ConnectList::ConnectList(int _n, int _m)
{
    nodelist = new NodeIntList(_n);
    edgelist = new EdgeList(_m);
}

ConnectList::~ConnectList()
{
    delete nodelist;
    delete edgelist;
}

void ConnectList::setValue(int x, int _value)
{
    nodelist->setValue(x, _value);
}

void ConnectList::addEdge(int _x, int _y, double _z)
{
    edgelist->addEdge(_x, _y, _z);
}

void ConnectList::setConnection(int _count)
{
    connectionCount = _count;
}

void ConnectList::print(std::ofstream &out)
{
    out << connectionCount << std::endl;
    nodelist->print(out);
    edgelist->print(out);
}
