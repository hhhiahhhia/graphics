//
//  lamp.h
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//

#ifndef __graphics__lamp__
#define __graphics__lamp__

#include <stdio.h>
#include "../../object.hpp"
#include "../../basicobject/lamp.hpp"
#include "../../basicobject/text.hpp"
#include "doorButton.h"
#include "bulb.h"
class SuperLamp:public Lamp{
private:
    bool ifChoosed;
    bool choosedFlag;
public:
    SuperLamp(DoorButton * _db);
    DoorButton * db;
    Bulb * mybulb;
    Text* mainText;
    virtual void script();
    virtual void clicked(){
        ifChoosed = 1 - ifChoosed;
        choosedFlag = 1;
        printf("lamp clicked!:%d\n",ifChoosed);
    };
};

#endif /* defined(__graphics__lamp__) */
