//
//  lyt.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "lyt.hpp"
#include "cone.h"
#include "table.h"
#include "lamp.h"
#include "door.h"
#include "doorButton.h"
#include "../../basicobject/cylinder.h"
#include "../../basicobject/text.hpp"
#include "../zyh/mainLight.hpp"

void lytPart(std::vector<Object*>* objectList)
{
    extern MainLight* mainLight;
    extern Text* mainText;
    Table * t1 = new Table(15,1,20,6);
    t1->location.x=12;
    t1->location.y=6;
    t1->location.z=-40;
    
    Door * door=new Door();
    //-100=>-98.4
    door->location=Vector3(50,7.5,-100);
    objectList->push_back(door);
    door->mainText = mainText;
    
    //0=>0.3
    DoorButton * doorbtn=new DoorButton(door);
    doorbtn->location=Vector3(6.5,0,-8);
    t1->addChild(doorbtn);
    SuperLamp * lamp=new SuperLamp(doorbtn);
    
    mainLight->theLamp = lamp;
    lamp->mainText = mainText;
    lamp->location.x =-1;
    lamp->location.y =4;
    lamp->location.z =8;
    t1->addChild(lamp);
    
    objectList->push_back(t1);

}