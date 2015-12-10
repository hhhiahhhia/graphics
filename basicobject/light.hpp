//
//  light.hpp
//  mygraphics
//
//  Created by zyhc on 12/10/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#ifndef light_hpp
#define light_hpp

#include <stdio.h>
#include "../object.hpp"
class Light : public Object
{
public:
    static int lightNumber;
    Vector3 ambient;
    Vector3 attenuation;
    Vector3 specular;
    Vector3 diffuse;
    int usedLight;
    bool open;
    Light();
};
class PointLight :public Light
{
public:
    Vector3 direction;
    float angle;
    Vector3 lightColor;
    
    PointLight(Vector3 lightColor)
    {
        angle = 180;
        attenuation = Vector3(1,0,0);
        open = true;
        specular = lightColor;
        diffuse = lightColor;
        ambient = Vector3(0,0,0);
    }
};

#endif /* light_hpp */
