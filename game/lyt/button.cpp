//
//  button.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "button.h"
#include <stdio.h>

void Button::clicked(){
    printf("Push button!");
    ifPushed = 1 - ifPushed;
    bulb->openFlag=ifPushed;
}