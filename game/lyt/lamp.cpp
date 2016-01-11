//
//  lamp.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "lamp.h"
#include "../../basicobject/cylinder.h"
#include "bulb.h"
#include "button.h"
#include <string>

SuperLamp::SuperLamp(DoorButton* _db){
    ifChoosed=0;
    choosedFlag = 0;
    db=_db;
    size = Vector3(0.15,0.15,0.15);
//    Cylinder * cover = new Cylinder(1,2,3,false,false);
//    cover->location.x=0;
//    cover->location.y=0;
//    cover->location.z=0;
//    addChild(cover);
//    
    Bulb * bulb = new Bulb(Vector3(1,0,1));
    bulb->location = Vector3(17,5,-12);
    bulb->angle=70;
    bulb->direction = Vector3(0,-1,0);
    bulb->size = Vector3(2,2,2);
    addChild(bulb);
    mybulb=bulb;
//
//    Cylinder * pillar = new Cylinder(0.2,0.2,5,true,true);
//    pillar->location.x=0;
//    pillar->location.y=-1;
//    pillar->location.z=0;
//    addChild(pillar);
//    
//    Cylinder * bottom = new Cylinder(2,2,0.5,true,true);
//    bottom->location.x=0;
//    bottom->location.y=-6;
//    bottom->location.z=0;
//    addChild(bottom);
//    
    Button *xbutton = new Button();
    addButton(xbutton);
//    button->location.x=1.0;
////    button->location.y=-5.8;
//    button->location.y=5;
//    button->location.z=0;
    xbutton->bulb=bulb;
//    addChild(button);
    
}


void SuperLamp::script(){
    if (keyPushed('r'))
    {
        ifChoosed = false;
    }
    if(ifChoosed){
        emission = Vector3(.7,.7,.7);
        mainText->text = string("use i j k l to move the lamp , r to release");
        if(keyPushed('j')){
            if (location.z<=10.5) {
                location.z+=0.1;
            }
        }
        if(keyPushed('l')){
            if(location.z>=-7.5){
                location.z-=0.1;
            }
        }
        if(keyPushed('i')){
            if (location.x>=-6.5) {
                location.x-=0.1;
            }
            
        }
        if(keyPushed('k')){
            if (location.x<=6.5) {
                location.x+=0.1;
            }
        }
    }
    else
    {
        if (choosedFlag)
        {
            emission = Vector3(-1,-1,-1);
            mainText->text = "...";
            choosedFlag = false;
        }
        
    }
    if (location.x>=0.9 && location.z<=-0.4 && mybulb->openFlag==true) {
        db->showFlag=true;
    }else{
        db->showFlag=false;
    }
}