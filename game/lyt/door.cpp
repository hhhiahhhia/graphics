//
//  door.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include <stdio.h>
#include "door.h"
extern Player* player;

Door::Door(){
    ifChoosed=false;
    showFlag=false;
    
    Cube * o1=new Cube();
    o1->size=Vector3(5,10,1);
    o1->location=Vector3(0,0,0);
    
    addChild(o1);
    
}

void Door::script(){
    if (ifChoosed && player->hasKey) {
        //open the door
    }
    
    if (showFlag) {
        //show the door
    }
}

void Door::clicked(){
    ifChoosed=1-ifChoosed;
    ifChoosed?printf("door choosed!\n"):printf("door cancel choosed!\n");
}