//
//  bulb.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__bulb__
#define __graphics__bulb__

#include <stdio.h>
#include "../../object.hpp"
#include "../../basicobject/light.hpp"

class Bulb:public PointLight
{
public:
    bool openFlag;
    Bulb(Vector3 v3):PointLight(v3)
    {
        disableTexture = true;
        openFlag = false;
        open=false;
        color = v3;
    }
    virtual void script();
    virtual void draw();
};


#endif /* defined(__graphics__bulb__) */
