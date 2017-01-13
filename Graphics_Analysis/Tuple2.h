//
//  Tuple2.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/12.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef TUPLE2_H
#define TUPLE2_H

// 排序用二元组

class Tuple2
{
public:
    int x;
    double y;
    
    Tuple2() : x(0), y(0.0) {}
    Tuple2(int _x, double _y) : x(_x), y(_y) {}
    ~Tuple2() {}
    
    bool operator< (const Tuple2& that) const
    {
        return this->y > that.y;
    }
};

#endif
