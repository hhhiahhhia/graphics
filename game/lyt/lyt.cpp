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
    
    objectList->push_back(t1);
    
//    Cylinder * cover = new Cylinder(5.0,10.0,10.0,false,false);
//    Cone * cover = new Cone();
//    cover->location.x=12;
//    cover->location.y=6;
//    cover->location.z=-50;
//    objectList->push_back(cover);

}