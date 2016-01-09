//
//  player.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 漏 2015 zyhc. All rights reserved.
//

#include "player.hpp"
#include "math.h"
#include <iostream>

Player::Player()
{
    PI = 3.1415926535897;
    tAngInc = PI / 60;
    tVerticalAng = 0;
    tHorizonAng = -PI / 2;
    tRadius = 400.0;
    preMouseX = 0;
    preMouseY = 0;
    hasKey=true;
}
void Player::script()
{
    if (mouseClicked)
    {
        if(preMouseX!=-1 && preMouseY!=-1 && mouseX!=-1 && mouseY!=-1) {
            double tDx = mouseX - preMouseX;
            double tDy = -mouseY + preMouseY;
            double tDis = sqrt(tDx*tDx+tDy*tDy);
            if(tDx > 0.) {
                tHorizonAng += tAngInc * tDx / tDis;
                if(tHorizonAng < 0.) { tHorizonAng += 2*PI; }
                if(tHorizonAng > 2*PI) { tHorizonAng -= 2*PI; }
            } else if(tDx < 0.) {
                tHorizonAng += tAngInc * tDx / tDis;
                if(tHorizonAng < 0.) { tHorizonAng += 2*PI; }
                if(tHorizonAng > 2*PI) { tHorizonAng -= 2*PI; }
            }
            if(tDy > 0.) {
                tVerticalAng = tVerticalAng + tAngInc * tDy / tDis;
                if(tVerticalAng > PI/2) { tVerticalAng = PI/2; }
            } else if(tDy < 0.) {
                tVerticalAng = tVerticalAng + tAngInc * tDy / tDis;
                if(tVerticalAng < -PI/2) { tVerticalAng = -PI/2; }
            }
            
            camera->center.x = camera->location.x + tRadius * cos(tVerticalAng) * cos(tHorizonAng);
            camera->center.y = camera->location.y + tRadius * sin(tVerticalAng);
            camera->center.z = camera->location.z + tRadius * cos(tVerticalAng) * sin(tHorizonAng);
        }
        
    }
    preMouseX = mouseX;
    preMouseY = mouseY;
    double fDistance = 0.1;
    if (keyPushed('a'))
    {
        camera->location.x+=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->center.x+=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->location.z-=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
        camera->center.z-=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
    }
    if (keyPushed('d'))
    {
        camera->location.x-=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->center.x-=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->location.z+=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
        camera->center.z+=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
    }
    if (keyPushed('w'))
    {
        camera->location.z+=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->center.z+=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->location.x+=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
        camera->center.x+=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
    }
    if (keyPushed('s'))
    {
        camera->location.z-=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->center.z-=fDistance * cos(tVerticalAng) * sin(tHorizonAng);
        camera->location.x-=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
        camera->center.x-=fDistance * cos(tVerticalAng) * cos(tHorizonAng);
    }
}
