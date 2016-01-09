//
//  door.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include <stdio.h>
#include "door.h"
#include "../../basicobject/cube.hpp"
extern Player* player;

DoorBorder::DoorBorder(){
    Cube * top = new Cube();
    top->size=Vector3(11,1,1.5);
    top->location=Vector3(0,11,0);
    top->color=Vector3(0.501,0.2,0);
    addChild(top);
    
    Cube * l = new Cube();
    l->size=Vector3(1,21,1.5);
    l->location=Vector3(-5,0,0);
    l->color=Vector3(0.501,0.2,0);
    addChild(l);
    
    Cube * r = new Cube();
    r->size=Vector3(1,21,1.5);
    r->location=Vector3(5,0,0);
    r->color=Vector3(0.501,0.2,0);
    addChild(r);
}

DoorPart::DoorPart(){
    ifOpen=false;
    
    Cube * cont = new Cube();
    cont->size=Vector3(9,21,1);
    cont->location=Vector3(4,0,0);
    addChild(cont);
    useTexture = true;
//    color = Vector3(1,1,1);
    texture = LoadTexture("door2.bmp", 650 , 406);
    
}

void DoorPart::script(){
    if(ifOpen){
        if(rotate.y>=-150){
            rotate.y-=1;
        }
    }
}

Door::Door(){
    ifChoosed=false;
    showFlag=false;
    firstFlag=true;
    
    DoorBorder * db = new DoorBorder();
    db->location=Vector3(0,0,0);
    addChild(db);
    
    DoorPart * dp = new DoorPart();
    dp->location=Vector3(-4,0,0);
    addChild(dp);
    rd=dp;
    
    Cube * out = new Cube();
    out->color=Vector3(1,1,1);
    out->size=Vector3(9,21,0.4);
    out->location=Vector3(0,0,-0.7);
    addChild(out);
}

void Door::script(){
    if (showFlag && firstFlag &&location.z == -100) {
        //show the door
        location.z+=1.6;
        showFlag=false;
        firstFlag=false;
    }
}

void Door::clicked(){
    if (player->hasKey) {
        rd->ifOpen=true;
    }
}