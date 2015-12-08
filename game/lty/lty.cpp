//
//  lty.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 婕?2015 zyhc. All rights reserved.
//

#include "lty.hpp"
#include "drawModel.h"
#include "drawQuadrangle.h"
#include "drawCube.h"

void ltyPart(std::vector<Object*>* objectList)
{
  drawModel *drawModelOne=new drawModel;
  objectList->push_back(drawModelOne);

  drawModel *drawModelOneWallOneFrontOne=new drawModel;
  drawModelOneWallOneFrontOne->color=Vector3(1.0,0.0,0.0);
  drawModelOneWallOneFrontOne->location=Vector3(100.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneFrontOne);
  drawModel *drawModelOneWallOneBackOne=new drawModel;
  drawModelOneWallOneBackOne->color=Vector3(1.0,1.0,0.0);
  drawModelOneWallOneBackOne->location=Vector3(0.0,0.0,-100.0);
  drawModelOneWallOneBackOne->rotate=Vector3(0.0,180.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneBackOne);
  drawModel *drawModelOneWallOneLeftOne=new drawModel;
  drawModelOneWallOneLeftOne->color=Vector3(0.0,1.0,0.0);
  drawModelOneWallOneLeftOne->rotate=Vector3(0.0,270.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneLeftOne);
  drawModel *drawModelOneWallOneRightOne=new drawModel;
  drawModelOneWallOneRightOne->color=Vector3(0.0,1.0,1.0);
  drawModelOneWallOneRightOne->location=Vector3(100.0,0.0,-100.0);
  drawModelOneWallOneRightOne->rotate=Vector3(0.0,90.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneRightOne);
  drawModel *drawModelOneWallOneTopOne=new drawModel;
  drawModelOneWallOneTopOne->color=Vector3(0.0,0.0,1.0);
  drawModelOneWallOneTopOne->location=Vector3(100.0,100.0,0.0);

  drawModelOneWallOneTopOne->rotate=Vector3(270.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneTopOne);
  drawModel *drawModelOneWallOneBottomOne=new drawModel;
  drawModelOneWallOneBottomOne->color=Vector3(1.0,0.0,1.0);
  drawModelOneWallOneBottomOne->location=Vector3(100.0,0.0,-100.0);
  drawModelOneWallOneBottomOne->rotate=Vector3(90.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneBottomOne);
  drawModel *drawModelOneWallOne=new drawModel;
  drawModelOneWallOne->location=Vector3(-50.0,50.0,0.0);
  drawModelOneWallOne->size=Vector3(50.0,50.0,1.0);
  drawModelOneWallOneFrontOne->addChild(drawModelOneWallOne);
  drawModelOneWallOneBackOne->addChild(drawModelOneWallOne);
  drawModelOneWallOneLeftOne->addChild(drawModelOneWallOne);
  drawModelOneWallOneRightOne->addChild(drawModelOneWallOne);
  drawModelOneWallOneTopOne->addChild(drawModelOneWallOne);
  drawModelOneWallOneBottomOne->addChild(drawModelOneWallOne);
  drawQuadrangle *drawModelOneWallOneQuadrangleOne=new drawQuadrangle;
  drawModelOneWallOne->addChild(drawModelOneWallOneQuadrangleOne);

  drawModel *drawModelOneTableOne=new drawModel;
  drawModelOneTableOne->color=Vector3(0.5,0.5,0.5);
  drawModelOneTableOne->location=Vector3(50.0,6.0,-30.0);
  drawModelOne->addChild(drawModelOneTableOne);
  drawModel *drawModelOneTableOneTabletopOne=new drawModel;
  drawModelOneTableOneTabletopOne->location=Vector3(0.0,1.0,0.0);
  drawModelOneTableOneTabletopOne->size=Vector3(5.0,1.0,5.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTabletopOne);
  drawCube *drawModelOneTableOneTabletopOneCubeOne=new drawCube;
  drawModelOneTableOneTabletopOne->addChild(drawModelOneTableOneTabletopOneCubeOne);
  drawModel *drawModelOneTableOneTableLegOneOne=new drawModel;
  drawModelOneTableOneTableLegOneOne->location=Vector3(3.0,0.0,-3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneOne);
  drawModel *drawModelOneTableOneTableLegOneTwo=new drawModel;

  drawModelOneTableOneTableLegOneTwo->location=Vector3(-3.0,0.0,-3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneTwo);
  drawModel *drawModelOneTableOneTableLegOneThree=new drawModel;
  drawModelOneTableOneTableLegOneThree->location=Vector3(-3.0,0.0,3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneThree);
  drawModel *drawModelOneTableOneTableLegOneFour=new drawModel;
  drawModelOneTableOneTableLegOneFour->location=Vector3(3.0,0.0,3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneFour);
  drawModel *drawModelOneTableOneTableLegOne=new drawModel;
  drawModelOneTableOneTableLegOne->location=Vector3(0.0,-3.0,0.0);
  drawModelOneTableOneTableLegOne->size=Vector3(1.0,3.0,1.0);
  drawModelOneTableOneTableLegOneOne->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneTwo->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneThree->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneFour->addChild(drawModelOneTableOneTableLegOne);
  drawCube *drawModelOneTableOneTableLegOneCubeOne=new drawCube;
  drawModelOneTableOneTableLegOne->addChild(drawModelOneTableOneTableLegOneCubeOne);
}
