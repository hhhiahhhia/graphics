//
//  decorations.hpp
//  mygraphics
//
//  Created by zyhc on 1/10/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef decorations_hpp
#define decorations_hpp

#include <stdio.h>
#include "importedobj.hpp"
class BigLamp:public ImportedObj{
public:
    BigLamp():ImportedObj("biglamp.obj")
    {
        color = Vector3(0.7,.7,.3);
    };
};
class Sofa:public ImportedObj{
public:
    Sofa():ImportedObj("office_chair.obj")
    {
        color = Vector3(.3,.3,.3);
        useTexture = true;
        texture = LoadTexture("sofa.bmp", 0, 0);
    };
};

#endif /* decorations_hpp */
