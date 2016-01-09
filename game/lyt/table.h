//
//  table.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__table__
#define __graphics__table__

#include <stdio.h>

#include "../../object.hpp"
#include "../../basicobject/cube.hpp"

class TableFace:public Cube{
public:
    TableFace(){
        useTexture = true;
        texture = LoadTexture("desk.bmp", 1002 , 950);
    }
};

class Table:public Object{
public:
    //params:
    //float x: width of x Axis of table
    //float y: height of y Axis of table
    //float z: width of z Axis of table
    //float locationy: table.location.y
    //leg of table is 1*(locationy-y)*1, you can set legx and legz in table.cpp
    Table(float x,float y,float z,float locationy);
};
#endif /* defined(__graphics__table__) */
