//
//  doorButton.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/9.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#include "doorButton.h"

void DoorButton::clicked(){
    ifPushed=1-ifPushed;
    door->showFlag=true;
}
