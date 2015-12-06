//
//  lty.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 婕?2015 zyhc. All rights reserved.
//

#include "lty.hpp"
#include "drawModel.h"
#include "drawWall.h"
#include "drawWallFront.h"
#include "drawWallBack.h"
#include "drawWallLeft.h"
#include "drawWallRight.h"
#include "drawWallTop.h"
#include "drawWallBottom.h"
void ltyPart(std::vector<Object*>* objectList)
{
  drawModel *drawModelOne=new drawModel;
  objectList->push_back(drawModelOne);

  drawWall *drawWallOne=new drawWall;
  drawModelOne->addChild(drawWallOne); // drawModelOne drawWallOne
  drawWallFront *drawWallFrontOne=new drawWallFront;
  drawWallFrontOne->color=Vector3(1.0,0.0,0.0);
  drawWallFrontOne->location=Vector3(0.0,0.0,0.0);
  drawWallFrontOne->size=Vector3(1.0,1.0,1.0);
  drawWallFrontOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallFrontOne); // drawWallOne drawWallFrontOne
  drawWallBack *drawWallBackOne=new drawWallBack;
  drawWallBackOne->color=Vector3(1.0,1.0,0.0);
  drawWallBackOne->location=Vector3(0.0,0.0,0.0);
  drawWallBackOne->size=Vector3(1.0,1.0,1.0);
  drawWallBackOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallBackOne); // drawWallOne drawWallBackOne
  drawWallLeft *drawWallLeftOne=new drawWallLeft;
  drawWallLeftOne->color=Vector3(0.0,1.0,0.0);
  drawWallLeftOne->location=Vector3(0.0,0.0,0.0);
  drawWallLeftOne->size=Vector3(1.0,1.0,1.0);
  drawWallLeftOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallLeftOne); // drawWallOne drawWallLeftOne
  drawWallRight *drawWallRightOne=new drawWallRight;
  drawWallRightOne->color=Vector3(0.0,1.0,1.0);
  drawWallRightOne->location=Vector3(0.0,0.0,0.0);
  drawWallRightOne->size=Vector3(1.0,1.0,1.0);
  drawWallRightOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallRightOne); // drawWallOne drawWallRightOne
  drawWallTop *drawWallTopOne=new drawWallTop;
  drawWallTopOne->color=Vector3(0.0,0.0,0.0);
  drawWallTopOne->location=Vector3(0.0,0.0,0.0);
  drawWallTopOne->size=Vector3(1.0,1.0,1.0);
  drawWallTopOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallTopOne); // drawWallOne drawWallTopOne
  drawWallBottom *drawWallBottomOne=new drawWallBottom;
  drawWallBottomOne->color=Vector3(0.0,0.0,0.0);
  drawWallBottomOne->location=Vector3(0.0,0.0,0.0);
  drawWallBottomOne->size=Vector3(1.0,1.0,1.0);
  drawWallBottomOne->rotate=Vector3(0.0,0.0,0.0);
  drawWallOne->addChild(drawWallBottomOne); // drawWallOne drawWallbottomOne
}
