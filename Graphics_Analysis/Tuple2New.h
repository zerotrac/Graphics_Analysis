//
//  Tuple2New.h
//  Graphics_Analysis
//
//  Created by 陈书新 on 2017/1/14.
//  Copyright © 2017年 陈书新. All rights reserved.
//

#ifndef TUPLE2NEW_H
#define TUPLE2NEW_H

class Tuple2New
{
public:
    int x;
    double y;
    int label;
    int fa;
    
    Tuple2New() : x(0), y(0.0), label(0), fa(-1) {}
    //Tuple2New(int _x, double _y, int _label) : x(_x), y(_y), label(_label), fa(-1) {}
    Tuple2New(int _x, double _y, int _label, int _fa) : x(_x), y(_y), label(_label), fa(_fa) {}
    ~Tuple2New() {}
    
    bool operator< (const Tuple2New& that) const
    {
        return this->y > that.y;
    }
};

#endif
