//
//  doorButton.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "doorButton.h"

DoorButton::DoorButton(Door * _door){
    door=_door;
    showFlag=false;
    ifPushed=false;
    Cube * bot = new Cube();
    bot->size=Vector3(1,0.5,1);
    bot->location=Vector3(0,0,0);
    addChild(bot);
    
    Cylinder * btn = new Cylinder(0.15, 0.15, 0.2, true, true);
    btn->location=Vector3(0,0.35,0);
    addChild(btn);
};

void DoorButton::script(){
    if (!showFlag) {
        location.y=0;
    }else{
        if(location.y == 3){
            return;
        }
        if(location.y == 0){
            location.y=0.3;
        }
    }
}

void DoorButton::clicked(){
//    ifPushed=1-ifPushed;
    ifPushed=true;
    door->showFlag=true;
}
