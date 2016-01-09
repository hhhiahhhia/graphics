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
    DoorButton(Door * _door){
        door=_door;
        ifPushed=false;
        Cube * bot = new Cube();
        bot->size=Vector3(3,1,3);
        bot->location=Vector3(0,0,0);
        addChild(bot);
        
        Cylinder * btn = new Cylinder(0.2, 0.2, 0.2, true, true);
        btn->location=Vector3(0,1,0);
        addChild(btn);
    };
    Door* door;
    bool ifPushed;
    virtual void clicked();
};

#endif /* defined(__graphics__doorButton__) */
