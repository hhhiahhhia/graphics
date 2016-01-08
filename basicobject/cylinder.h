//
//  cylinder.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__cylinder__
#define __graphics__cylinder__

#include <stdio.h>
#include "../object.hpp"

class Cylinder:public Object{
public:
    double base;
    double top;
    double height;
    bool ifTopCircle;
    bool ifBaseCircle;
    Cylinder(double _base, double _top,double _height,bool _ifTopCircle,bool _ifBaseCircle);
    virtual void draw();
};

#endif /* defined(__graphics__cylinder__) */
