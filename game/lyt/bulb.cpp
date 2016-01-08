//
//  bulb.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "bulb.h"
void Bulb::draw(){
    glutSolidSphere(0.5,16,16);
}

void Bulb::script(){
    open=openFlag;
}