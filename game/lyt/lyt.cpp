//
//  lyt.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "lyt.hpp"
#include "cone.h"

void lytPart(std::vector<Object*>* objectList)
{
    Cone * cone1 = new Cone();
    cone1->location.x=80;
    cone1->location.y=0;
    cone1->location.z=-30;
    cone1->rotate.x=90;
    cone1->rotate.y=30;
    objectList->push_back(cone1);
}