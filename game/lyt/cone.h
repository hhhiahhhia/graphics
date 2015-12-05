//
//  cone.h
//  graphics
//
//  Created by 逸婷 李 on 15/12/4.
//  Copyright (c) 2015年 逸婷 李. All rights reserved.
//

#ifndef __graphics__cone__
#define __graphics__cone__

#include <stdio.h>
#include "../../object.hpp"

class Cone:public Object{
    virtual void script();
    virtual void draw();
};

#endif /* defined(__graphics__cone__) */
