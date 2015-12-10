//
//  light.cpp
//  mygraphics
//
//  Created by zyhc on 12/10/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "light.hpp"
#include <iostream>
int Light::lightNumber;
Light::Light()
{
    attenuation = Vector3(1,0,0);
    if (lightNumber==8)
    {
        std::cout<<"too many light"<<std::endl;
        throw this;
    }
    lightNumber++;
    usedLight = GL_LIGHT0 + lightNumber -1;
    isLight = true;
}