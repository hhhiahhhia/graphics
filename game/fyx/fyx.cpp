#include "fyx.hpp"
#include "MyCylinder.h"
#include "Cylinder.h"

void fyxPart(std::vector<Object*>* objectList)
{
	Cylinder *CylinderOne = new Cylinder;
	objectList->push_back(CylinderOne);

    	MyCylinder * CylinderOneOne = new MyCylinder();
    	CylinderOneOne->color = Vector3(0.8,0.0,0.6);
	CylinderOneOne->location = Vector3(60,3,-3);
	CylinderOneOne->rotate = Vector3(0,90,0);
	CylinderOne->addChild(CylinderOneOne);
}

