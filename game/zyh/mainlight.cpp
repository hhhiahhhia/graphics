//
//  mainlight.cpp
//  mygraphics
//
//  Created by zyhc on 12/10/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "mainlight.hpp"
#include <ctime>
void MainLight::script()
{
    if (!open)
    {
        theLamp->emission = Vector3(1,0,0);
    }
    else
    {
        theLamp->emission = Vector3(-1,-1,-1);
    }
    if (keyPushed('0'))
    {
        openFlag = true;
    }
    if (!keyPushed('0'))
    {
        if (openFlag)
        {
            open = 1 - open;
            openFlag = false;
        }
    }
}