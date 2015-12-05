//
//  object.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "object.hpp"
#include "game/lyt/lyt.hpp"
#include "game/zyh/zyh.hpp"
#include "game/lty/lty.hpp"
#include "game/xft/xft.hpp"
#include "game/fyx/fyx.hpp"
bool Object::keyDown[256],Object::mouseClicked,Object::mouseClickedRight;
double Object::keyLoc[256][2];
double Object::mouseX,Object::mouseY;
void Object::upKey(unsigned char key,int x,int y)
{
    keyDown[key] = false;
}
void Object::downKey(unsigned char key,int x,int y)
{
    keyDown[key] = true;
    keyLoc[key][0] = x;
    keyLoc[key][1] = y;
}
bool Object::keyPushed(unsigned char key)
{
    return keyDown[key];
}
void addObject(std::vector<Object*>* objectList)
{
    ltyPart(objectList);
    zyhPart(objectList);
    lytPart(objectList);
    xftPart(objectList);
    fyxPart(objectList);
}
