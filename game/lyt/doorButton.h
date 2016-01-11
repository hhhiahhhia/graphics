//
//  doorButton.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__doorButton__
#define __graphics__doorButton__

#include <stdio.h>
#include "../../object.hpp"
#include "../../basicobject/cylinder.h"
#include "../../basicobject/cube.hpp"
#include "door.h"

class DoorButton:public Object{
public:
    Cylinder * btn;
    DoorButton(Door * _door);
    Door* door;
    bool ifPushed;
    bool showFlag;
    virtual void clicked();
    virtual void script();
};

#endif /* defined(__graphics__doorButton__) */
