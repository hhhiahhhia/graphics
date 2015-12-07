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
  drawModelOneWallOneFrontOne->bColorFlag=true;
  drawModelOneWallOneFrontOne->color=Vector3(1.0,0.0,0.0);
  drawModelOneWallOneFrontOne->bLocationFlag=true;
  drawModelOneWallOneFrontOne->location=Vector3(100.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneFrontOne);
  drawModel *drawModelOneWallOneBackOne=new drawModel;
  drawModelOneWallOneBackOne->bColorFlag=true;
  drawModelOneWallOneBackOne->color=Vector3(1.0,1.0,0.0);
  drawModelOneWallOneBackOne->bLocationFlag=true;
  drawModelOneWallOneBackOne->location=Vector3(0.0,0.0,-100.0);
  drawModelOneWallOneBackOne->bRotateFlag=true;
  drawModelOneWallOneBackOne->rotate=Vector3(0.0,180.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneBackOne);
  drawModel *drawModelOneWallOneLeftOne=new drawModel;
  drawModelOneWallOneLeftOne->bColorFlag=true;
  drawModelOneWallOneLeftOne->color=Vector3(0.0,1.0,0.0);
  drawModelOneWallOneLeftOne->bRotateFlag=true;
  drawModelOneWallOneLeftOne->rotate=Vector3(0.0,270.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneLeftOne);
  drawModel *drawModelOneWallOneRightOne=new drawModel;
  drawModelOneWallOneRightOne->bColorFlag=true;
  drawModelOneWallOneRightOne->color=Vector3(0.0,1.0,1.0);
  drawModelOneWallOneRightOne->bLocationFlag=true;
  drawModelOneWallOneRightOne->location=Vector3(100.0,0.0,-100.0);
  drawModelOneWallOneRightOne->bRotateFlag=true;
  drawModelOneWallOneRightOne->rotate=Vector3(0.0,90.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneRightOne);
  drawModel *drawModelOneWallOneTopOne=new drawModel;
  drawModelOneWallOneTopOne->bColorFlag=true;
  drawModelOneWallOneTopOne->color=Vector3(0.0,0.0,1.0);
  drawModelOneWallOneTopOne->bLocationFlag=true;
  drawModelOneWallOneTopOne->location=Vector3(100.0,100.0,0.0);
  drawModelOneWallOneTopOne->bRotateFlag=true;
  drawModelOneWallOneTopOne->rotate=Vector3(270.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneTopOne);
  drawModel *drawModelOneWallOneBottomOne=new drawModel;
  drawModelOneWallOneBottomOne->bColorFlag=true;
  drawModelOneWallOneBottomOne->color=Vector3(1.0,0.0,1.0);
  drawModelOneWallOneBottomOne->bLocationFlag=true;
  drawModelOneWallOneBottomOne->location=Vector3(100.0,0.0,-100.0);
  drawModelOneWallOneBottomOne->bRotateFlag=true;
  drawModelOneWallOneBottomOne->rotate=Vector3(90.0,0.0,0.0);
  drawModelOne->addChild(drawModelOneWallOneBottomOne);
  drawModel *drawModelOneWallOne=new drawModel;
  drawModelOneWallOne->bLocationFlag=true;
  drawModelOneWallOne->location=Vector3(-50.0,50.0,0.0);
  drawModelOneWallOne->bSizeFlag=true;
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
  drawModelOneTableOne->bColorFlag=true;
  drawModelOneTableOne->color=Vector3(0.5,0.5,0.5);
  drawModelOneTableOne->bLocationFlag=true;
  drawModelOneTableOne->location=Vector3(50.0,6.0,-30.0);
  drawModelOne->addChild(drawModelOneTableOne);
  drawModel *drawModelOneTableOneTabletopOne=new drawModel;
  drawModelOneTableOneTabletopOne->bLocationFlag=true;
  drawModelOneTableOneTabletopOne->location=Vector3(0.0,1.0,0.0);
  drawModelOneTableOneTabletopOne->bSizeFlag=true;
  drawModelOneTableOneTabletopOne->size=Vector3(5.0,1.0,5.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTabletopOne);
  drawCube *drawModelOneTableOneTabletopOneCubeOne=new drawCube;
  drawModelOneTableOneTabletopOne->addChild(drawModelOneTableOneTabletopOneCubeOne);
  drawModel *drawModelOneTableOneTableLegOneOne=new drawModel;
  drawModelOneTableOneTableLegOneOne->bLocationFlag=true;
  drawModelOneTableOneTableLegOneOne->location=Vector3(3.0,0.0,-3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneOne);
  drawModel *drawModelOneTableOneTableLegOneTwo=new drawModel;
  drawModelOneTableOneTableLegOneTwo->bLocationFlag=true;
  drawModelOneTableOneTableLegOneTwo->location=Vector3(-3.0,0.0,-3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneTwo);
  drawModel *drawModelOneTableOneTableLegOneThree=new drawModel;
  drawModelOneTableOneTableLegOneThree->bLocationFlag=true;
  drawModelOneTableOneTableLegOneThree->location=Vector3(-3.0,0.0,3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneThree);
  drawModel *drawModelOneTableOneTableLegOneFour=new drawModel;
  drawModelOneTableOneTableLegOneFour->bLocationFlag=true;
  drawModelOneTableOneTableLegOneFour->location=Vector3(3.0,0.0,3.0);
  drawModelOneTableOne->addChild(drawModelOneTableOneTableLegOneFour);
  drawModel *drawModelOneTableOneTableLegOne=new drawModel;
  drawModelOneTableOneTableLegOne->bLocationFlag=true;
  drawModelOneTableOneTableLegOne->location=Vector3(0.0,-3.0,0.0);
  drawModelOneTableOneTableLegOne->bSizeFlag=true;
  drawModelOneTableOneTableLegOne->size=Vector3(1.0,3.0,1.0);
  drawModelOneTableOneTableLegOneOne->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneTwo->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneThree->addChild(drawModelOneTableOneTableLegOne);
  drawModelOneTableOneTableLegOneFour->addChild(drawModelOneTableOneTableLegOne);
  drawCube *drawModelOneTableOneTableLegOneCubeOne=new drawCube;
  drawModelOneTableOneTableLegOne->addChild(drawModelOneTableOneTableLegOneCubeOne);
}
