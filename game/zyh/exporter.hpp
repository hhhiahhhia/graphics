//
//  exporter.hpp
//  mygraphics
//
//  Created by zyhc on 1/8/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef exporter_hpp
#define exporter_hpp

#include <stdio.h>
#include "../../object.hpp"
class Exporter : public Object
{
    static int objNum;
    virtual void script();
};
#endif /* exporter_hpp */
