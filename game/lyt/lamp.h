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
#include "bulb.h"
class Lamp:public Object{
private:
    bool ifChoosed=0;
public:
    Lamp();
    virtual void script();
    virtual void clicked(){
        ifChoosed = 1 - ifChoosed;
        printf("lamp clicked!:%d",ifChoosed);
    };
};

#endif /* defined(__graphics__lamp__) */
