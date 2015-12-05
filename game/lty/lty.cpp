//
//  lty.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 漏 2015 zyhc. All rights reserved.
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
  drawWallOne->addChild(drawWallFrontOne); // drawWallOne drawWallFrontOne
  drawWallBack *drawWallBackOne=new drawWallBack;
  drawWallOne->addChild(drawWallBackOne); // drawWallOne drawWallBackOne
  drawWallLeft *drawWallLeftOne=new drawWallLeft;
  drawWallOne->addChild(drawWallLeftOne); // drawWallOne drawWallLeftOne
  drawWallRight *drawWallRightOne=new drawWallRight;
  drawWallOne->addChild(drawWallRightOne); // drawWallOne drawWallRightOne
  drawWallTop *drawWallTopOne=new drawWallTop;
  drawWallOne->addChild(drawWallTopOne); // drawWallOne drawWallTopOne
  drawWallBottom *drawWallBottomOne=new drawWallBottom;
  drawWallOne->addChild(drawWallBottomOne); // drawWallOne drawWallbottomOne
}
