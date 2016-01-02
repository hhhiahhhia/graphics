//
//  rotatingtriangle.hpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#ifndef rotatingtriangle_hpp
#define rotatingtriangle_hpp

#include <stdio.h>
#include "../../basicobject/triangle.hpp"
#include "../../basicobject/teapot.hpp"
class RotatingTriangle:public Teapot
{
    bool ifrotate;
    
public:
    RotatingTriangle()
    {
        useTexture = true;
        texture = LoadTexture("monet.bmp", 512 , 512);
    }
    virtual void clicked()
    {
        printf("lallaal !");
        ifrotate = 1 - ifrotate;
    }
    virtual void script();
};
#endif /* rotatingtriangle_hpp */
