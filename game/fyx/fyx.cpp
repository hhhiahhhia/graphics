#include "fyx.hpp"
#include "MyCylinder.h"
#include "MyObject.h"
#include "NewWall.h"
#include "Top.h"
#include "Bottom.h"

void fyxPart(std::vector<Object*>* objectList)
{
	MyObject *MyObjectOne = new MyObject;
	objectList->push_back(MyObjectOne);

	MyCylinder * CylinderOne = new MyCylinder();
	CylinderOne->color = Vector3(0.8,0.9,0.6);
	CylinderOne->location = Vector3(60,5,-3);
	CylinderOne->rotate = Vector3(0,90,0);
	MyObjectOne->addChild(CylinderOne);

	MyObject *FrontWall = new MyObject;
  	FrontWall->location = Vector3(100.0,0.0,0.0);
  	MyObjectOne->addChild(FrontWall);
  	MyObject *BackWall = new MyObject;
  	BackWall->location = Vector3(0.0,0.0,-100.0);
  	BackWall->rotate = Vector3(0.0,180.0,0.0);
  	MyObjectOne->addChild(BackWall);
  	MyObject *LeftWall = new MyObject;
  	LeftWall->rotate = Vector3(0.0,270.0,0.0);
  	MyObjectOne->addChild(LeftWall);
	MyObject *RightWall = new MyObject;
  	RightWall->location = Vector3(100.0,0.0,-100.0);
  	RightWall->rotate = Vector3(0.0,90.0,0.0);
  	MyObjectOne->addChild(RightWall);
  	MyObject *TopWall = new MyObject;
  	TopWall->location = Vector3(100.0,100.0,0.0);
  	TopWall->rotate = Vector3(270.0,0.0,0.0);
  	MyObjectOne->addChild(TopWall);
  	MyObject *BottomWall = new MyObject;
  	BottomWall->location = Vector3(100.0,0.0,-100.0);
  	BottomWall->rotate = Vector3(90.0,0.0,0.0);
  	MyObjectOne->addChild(BottomWall);

  	NewWall *AllWall = new NewWall;
  	AllWall->location = Vector3(-50.0,50.0,0.0);
  	AllWall->size = Vector3(100.0,100.0,1.0);
  	FrontWall->addChild(AllWall);
  	BackWall->addChild(AllWall);
  	LeftWall->addChild(AllWall);
  	RightWall->addChild(AllWall);

	Top * Topt = new Top;
  	Topt->location = Vector3(-50.0,50.0,0.0);
  	Topt->size = Vector3(100.0,100.0,1.0);
  	TopWall->addChild(Topt);

  	Bottom * Bottomt = new Bottom;
  	Bottomt->location = Vector3(-50.0,50.0,0.0);
  	Bottomt->size = Vector3(100.0,100.0,1.0);
  	BottomWall->addChild(Bottomt);

}

