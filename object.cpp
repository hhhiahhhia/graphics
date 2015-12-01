//
//  object.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "object.hpp"
#include "lyt.hpp"
#include "zyh.hpp"
#include "lty.hpp"
#include "name1.hpp"
#include "name2.hpp"
void addObject(std::vector<Object*>* objectList)
{
    ltyPart(objectList);
    zyhPart(objectList);
    lytPart(objectList);
    name1Part(objectList);
    name2Part(objectList);
}