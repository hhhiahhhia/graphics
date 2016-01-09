//
//  mainlight.hpp
//  mygraphics
//
//  Created by zyhc on 12/10/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#ifndef mainlight_hpp
#define mainlight_hpp

#include <stdio.h>
#include "../../basicobject/light.hpp"
class MainLight:public PointLight
{
private:
    bool openFlag;
public:
    Object* theLamp;
    MainLight(Vector3 v3):PointLight(v3)
    {
        openFlag = false;
    }
    virtual void script();
};
#endif /* mainlight_hpp */
