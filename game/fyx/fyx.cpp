#include "fyx.hpp"
#include "MyCylinder.h"

void fyxPart(std::vector<Object*>* objectList)
{
    MyCylinder * C1 = new MyCylinder(); 
	C1->bLocationFlag = true;
    C1->location.x = 60;
    C1->location.y = 3;
    C1->location.z = -3;
	C1->bRotateFlag = true;
	C1->rotate.y = 90;
    objectList->push_back(C1);
}
