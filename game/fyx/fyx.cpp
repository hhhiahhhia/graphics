#include "fyx.hpp"
#include "MyCylinder.h"
#include "MyObject.h"
#include "NewWall.h"
#include "Top.h"
#include "Bottom.h"
#include "../../basicobject/cube.hpp"
//#include "Door.h"
#include "Out.h"

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
  	AllWall->size = Vector3(100.0,100.0,2.0);
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

//  	MyObject *CompleteDoor = new MyObject;
//  	CompleteDoor->location = Vector3(50.0,10.0,-98.4);
//  	MyObjectOne->addChild(CompleteDoor);
//  	Door *MyDoor = new Door;
//  	MyDoor->location = Vector3(0.0,0.0,0.0);
//  	MyDoor->size = Vector3(12.0,20.0,1.0);
//  	CompleteDoor->addChild(MyDoor);
//  	Out *DoorOut = new Out;
//  	DoorOut->color = Vector3(0.0,0.0,0.0);
//  	DoorOut->location = Vector3(0.0,0.0,-1.0);
//  	DoorOut->size = Vector3(12.0,20.0,1.0);
//  	CompleteDoor->addChild(DoorOut);
//  	Cube *Doorbar1 = new Cube;
//  	Doorbar1->color = Vector3(0.501,0.2,0);
//  	Doorbar1->location = Vector3(-6.0,0.0,0.0);
//  	Doorbar1->size = Vector3(1.0,21.0,2.0);
//  	CompleteDoor->addChild(Doorbar1);
//  	Cube *Doorbar2 = new Cube;
//  	Doorbar2->color = Vector3(0.501,0.2,0);
//  	Doorbar2->location = Vector3(6.0,0.0,0.0);
//  	Doorbar2->size = Vector3(1.0,21.0,2.0);
//  	CompleteDoor->addChild(Doorbar2);
//  	Cube *Doorbar3 = new Cube;
//  	Doorbar3->color = Vector3(0.501,0.2,0);
//  	Doorbar3->location = Vector3(0.0,10.0,0.0);
//  	Doorbar3->size = Vector3(12.0,1.0,2.0);
//  	CompleteDoor->addChild(Doorbar3);
}


