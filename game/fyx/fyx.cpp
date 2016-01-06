#include "fyx.hpp"
#include "MyCylinder.h"
#include "MyObject.h"
#include "NewWall.h"
#include "../../basicobject/cube.hpp"
#include "Top.h"
#include "Bottom.h"

void fyxPart(std::vector<Object*>* objectList)
{
	MyObject *MyObjectOne = new MyObject;
	objectList->push_back(MyObjectOne);

	MyCylinder * CylinderOneOne = new MyCylinder();
    	CylinderOneOne->color = Vector3(0.8,0.9,0.6);
	CylinderOneOne->location = Vector3(60,5,-3);
	CylinderOneOne->rotate = Vector3(0,90,0);
	MyObjectOne->addChild(CylinderOneOne);

	MyObject *drawModelOneWallOneFrontOne=new MyObject;
  	drawModelOneWallOneFrontOne->location=Vector3(100.0,0.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneFrontOne);
  	MyObject *drawModelOneWallOneBackOne=new MyObject;
  	drawModelOneWallOneBackOne->location=Vector3(0.0,0.0,-100.0);
  	drawModelOneWallOneBackOne->rotate=Vector3(0.0,180.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneBackOne);
  	MyObject *drawModelOneWallOneLeftOne=new MyObject;
  	drawModelOneWallOneLeftOne->rotate=Vector3(0.0,270.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneLeftOne);
	MyObject *drawModelOneWallOneRightOne = new MyObject;
  	drawModelOneWallOneRightOne->location=Vector3(100.0,0.0,-100.0);
  	drawModelOneWallOneRightOne->rotate=Vector3(0.0,90.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneRightOne);
  	MyObject *drawModelOneWallOneTopOne=new MyObject;
  	drawModelOneWallOneTopOne->location=Vector3(100.0,100.0,0.0);
  	drawModelOneWallOneTopOne->rotate=Vector3(270.0,0.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneTopOne);
  	MyObject *drawModelOneWallOneBottomOne=new MyObject;
  	drawModelOneWallOneBottomOne->location=Vector3(100.0,0.0,-100.0);
  	drawModelOneWallOneBottomOne->rotate=Vector3(90.0,0.0,0.0);
  	MyObjectOne->addChild(drawModelOneWallOneBottomOne);

  	NewWall *drawModelOneWallOne=new NewWall;
  	drawModelOneWallOne->location=Vector3(-50.0,50.0,0.0);
  	drawModelOneWallOne->size=Vector3(100.0,100.0,1.0);
  	drawModelOneWallOneFrontOne->addChild(drawModelOneWallOne);
  	drawModelOneWallOneBackOne->addChild(drawModelOneWallOne);
  	drawModelOneWallOneLeftOne->addChild(drawModelOneWallOne);
  	drawModelOneWallOneRightOne->addChild(drawModelOneWallOne);
  	Cube *drawModelOneWallOneQuadrangleOne=new Cube;
	drawModelOneWallOneQuadrangleOne->rotate = Vector3(0.0,0.0,90.0);
  	drawModelOneWallOne->addChild(drawModelOneWallOneQuadrangleOne);

	Top *drawModelOneWallTwo=new Top;
  	drawModelOneWallTwo->location=Vector3(-50.0,50.0,0.0);
  	drawModelOneWallTwo->size=Vector3(100.0,100.0,1.0);
  	drawModelOneWallOneTopOne->addChild(drawModelOneWallTwo);
  	Cube * drawModelOneWallOneQuadrangleTwo=new Cube;
  	drawModelOneWallTwo->addChild(drawModelOneWallOneQuadrangleTwo);

  	Bottom *drawModelOneWallThree=new Bottom;
  	drawModelOneWallThree->location=Vector3(-50.0,50.0,0.0);
  	drawModelOneWallThree->size=Vector3(100.0,100.0,1.0);
  	drawModelOneWallOneBottomOne->addChild(drawModelOneWallThree);
  	Cube * drawModelOneWallOneQuadrangleThree=new Cube;
  	drawModelOneWallThree->addChild(drawModelOneWallOneQuadrangleThree);
}

