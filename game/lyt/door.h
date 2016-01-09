//
//  door.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__door__
#define __graphics__door__

#include <stdio.h>
#include "../../object.hpp"
#include "../../basicobject/cube.hpp"
#include "../zyh/player.hpp"

class Door:public Object{
public:
    Door();
    Cube * realdoor;
    bool ifChoosed;
    bool showFlag;
    virtual void clicked();
    virtual void script();
};

#endif /* defined(__graphics__door__) */
