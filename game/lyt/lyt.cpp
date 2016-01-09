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

void lytPart(std::vector<Object*>* objectList)
{
    Table * t1 = new Table(15,1,20,6);
    t1->location.x=12;
    t1->location.y=6;
    t1->location.z=-40;
   
    SuperLamp * lamp=new SuperLamp();
    lamp->location.x =0;
    lamp->location.y =4;
    lamp->location.z =0;
    t1->addChild(lamp);
    
    Door * door=new Door();
    door->location=Vector3(0,0,-50);
    objectList->push_back(door);
    
    DoorButton * doorbtn=new DoorButton(door);
    doorbtn->location=Vector3(0,2,0);
    t1->addChild(doorbtn);
    
    objectList->push_back(t1);

}