//
//  table.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "table.h"
#include "../../basicobject/cube.hpp"
#include "lamp.h"
Table::Table(float x,float y,float z,float locationy){
    float legx=1;
    float legz=1;
    float legy=locationy-y;
    float offx=(x-2-2*legx)/2;
    float offy=locationy/2;
    float offz=(z-0.5-legz)/2;
    
    Cube * c1=new Cube();
    c1->location.x =0;
    c1->location.y =0;
    c1->location.z =0;
    c1->size = Vector3(x,y,z);//15,1,20
    addChild(c1);
    
    Cube * c2=new Cube();
    c2->location.x =-offx;
    c2->location.y =-offy;
    c2->location.z =offz;
    c2->size = Vector3(legx,legy,legz);
    addChild(c2);
    
    Cube * c3=new Cube();
    c3->location.x =offx;
    c3->location.y =-offy;
    c3->location.z =offz;
    c3->size = Vector3(legx,legy,legz);
    addChild(c3);
    
    Cube * c4=new Cube();
    c4->location.x =-offx;
    c4->location.y =-offy;
    c4->location.z =-offz;
    c4->size = Vector3(legx,legy,legz);
    addChild(c4);
    
    Cube * c5=new Cube();
    c5->location.x =offx;
    c5->location.y =-offy;
    c5->location.z =-offz;
    c5->size = Vector3(legx,legy,legz);
    addChild(c5);
    

    
    
}
