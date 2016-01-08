//
//  button.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__button__
#define __graphics__button__

#include <stdio.h>
#include "bulb.h"
#include "../../basicobject/cylinder.h"

class Button:public Cylinder{
public:
    Button():Cylinder(2,2,3,true,true){
        ifPushed=false;
    }
    Bulb* bulb;
    bool ifPushed;
    virtual void clicked();

};

#endif /* defined(__graphics__button__) */
