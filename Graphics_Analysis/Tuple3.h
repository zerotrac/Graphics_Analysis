//
//  Tuple3.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef TUPLE3_H
#define TUPLE3_H

// 排序用三元组

class Tuple3
{
public:
    int x;
    int y;
    double z;
    
    Tuple3() : x(0), y(0), z(0.0) {}
    Tuple3(int _x, int _y, double _z) : x(_x), y(_y), z(_z) {}
    ~Tuple3() {}
    
public:
    bool operator< (const Tuple3& that) const
    {
        return this->z < that.z;
    }
};

#endif
