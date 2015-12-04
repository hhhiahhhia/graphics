//
//  cone.cpp
//  graphics
//
//  Created by 逸婷 李 on 15/12/4.
//  Copyright (c) 2015年 逸婷 李. All rights reserved.
//

#include "cone.h"

void Cone::script(){
    rotate.z+=1;
}

void Cone::draw(){
    GLUquadricObj *objCylinder = gluNewQuadric();
    gluCylinder(objCylinder, 10.0, 0.0, 30.0, 32, 5);
}