//
//  lty.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 婕?2015 zyhc. All rights reserved.
//

#include "lty.hpp"
#include "drawModel.h"
#include "../zyh/player.hpp"
#include "doorkey.hpp"

void ltyPart(std::vector<Object*>* objectList)
{
  Model *iModel=new Model;
  objectList->push_back(iModel);
    extern Player* player;
    DoorKey *dk = new DoorKey;
    dk->size = Vector3(20,20,20);
//    dk->color = Vector3(.5,.5,0);
    dk->rotate.x = 90;
    dk->mainPlayer = player;
    dk->location = Vector3(83,1.3,-83);
    objectList->push_back(dk);
  /*
  drawModel *drawModelOneSafeOne=new drawModel;
  drawModelOneSafeOne->location=Vector3(20.0,0.0,-70.0);
  drawModelOne->addChild(drawModelOneSafeOne);
  drawModel *drawModelOneSafeOneFrontOne=new drawModel;
  drawModelOneSafeOne->addChild(drawModelOneSafeOneFrontOne);
  drawModel *drawModelOneSafeOneFrontTwo=new drawModel;
  drawModelOneSafeOneFrontTwo->location=Vector3(5.0,10.0,8.5);
  drawModelOneSafeOneFrontTwo->size=Vector3(10.0,20.0,1.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneFrontTwo);
  drawModel *drawModelOneSafeOneBackOne=new drawModel;
  drawModelOneSafeOneBackOne->location=Vector3(0.0,10.0,-9.5);
  drawModelOneSafeOneBackOne->size=Vector3(20.0,20.0,1.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneBackOne);
  drawModel *drawModelOneSafeOneLeftOne=new drawModel;
  drawModelOneSafeOneLeftOne->location=Vector3(-10.0,10.0,0.0);
  drawModelOneSafeOneLeftOne->size=Vector3(1.0,20.0,20.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneLeftOne);
  drawModel *drawModelOneSafeOneRightOne=new drawModel;
  drawModelOneSafeOneRightOne->location=Vector3(10.0,10.0,0.0);
  drawModelOneSafeOneRightOne->size=Vector3(1.0,20.0,20.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneRightOne);
  drawModel *drawModelOneSafeOneTopOne=new drawModel;
  drawModelOneSafeOneTopOne->location=Vector3(0.0,19.5,0.0);
  drawModelOneSafeOneTopOne->size=Vector3(20.0,1.0,20.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneTopOne);
  drawModel *drawModelOneSafeOneBottomOne=new drawModel;
  drawModelOneSafeOneBottomOne->location=Vector3(0.0,0.5,0.0);
  drawModelOneSafeOneBottomOne->size=Vector3(20.0,1.0,20.0);
  drawModelOneSafeOne->addChild(drawModelOneSafeOneBottomOne);
  drawModel *drawModelOneSafeOneFrontOneBigOne=new drawModel;
  drawModelOneSafeOneFrontOneBigOne->color=Vector3(1.0,0.0,0.0);
  drawModelOneSafeOneFrontOneBigOne->location=Vector3(-5.0,10.0,9.5);
  drawModelOneSafeOneFrontOneBigOne->size=Vector3(10.0,20.0,1.0);
  drawModelOneSafeOneFrontOne->addChild(drawModelOneSafeOneFrontOneBigOne);
  drawModel *drawModelOneSafeOneFrontOneSmallOne=new drawModel;
  drawModelOneSafeOneFrontOne->addChild(drawModelOneSafeOneFrontOneSmallOne);

  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitOne=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitOne->location=Vector3(-7.0,11.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitOne);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitTwo=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitTwo->location=Vector3(-6.0,11.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitTwo);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitThree=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitThree->location=Vector3(-5.0,11.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitThree);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitFour=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitFour->location=Vector3(-7.0,10.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFour);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitFive=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitFive->location=Vector3(-6.0,10.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFive);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitSix=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitSix->location=Vector3(-5.0,10.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitSix);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitSeven=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitSeven->location=Vector3(-7.0,9.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitSeven);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitEight=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitEight->location=Vector3(-6.0,9.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitEight);
  drawDigit *drawModelOneSafeOneFrontOneSmallOneDigitNine=new drawDigit;
  drawModelOneSafeOneFrontOneSmallOneDigitNine->location=Vector3(-5.0,9.0,10.0);
  drawModelOneSafeOneFrontOneSmallOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitNine);

  drawCube *drawModelOneSafeOneFrontOneBigOneCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneBigOneCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneBigOneCubeOne->texture=LoadTexture("11.bmp",512,512);
  drawModelOneSafeOneFrontOneBigOne->addChild(drawModelOneSafeOneFrontOneBigOneCubeOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitOneCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitOneCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitOneCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitOneCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitOneQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitOneQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitOneQuadrangleOne->texture=LoadTexture("1.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitOneQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitOne->addChild(drawModelOneSafeOneFrontOneSmallOneDigitOneQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitTwoCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitTwoCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitTwoCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitTwo->addChild(drawModelOneSafeOneFrontOneSmallOneDigitTwoCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitTwoQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitTwoQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitTwoQuadrangleOne->texture=LoadTexture("2.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitTwoQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitTwo->addChild(drawModelOneSafeOneFrontOneSmallOneDigitTwoQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitThreeCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitThreeCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitThreeCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitThree->addChild(drawModelOneSafeOneFrontOneSmallOneDigitThreeCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitThreeQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitThreeQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitThreeQuadrangleOne->texture=LoadTexture("3.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitThreeQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitThree->addChild(drawModelOneSafeOneFrontOneSmallOneDigitThreeQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitFourCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitFourCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitFourCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitFour->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFourCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitFourQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitFourQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitFourQuadrangleOne->texture=LoadTexture("4.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitFourQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitFour->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFourQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitFiveCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitFiveCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitFiveCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitFive->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFiveCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitFiveQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitFiveQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitFiveQuadrangleOne->texture=LoadTexture("5.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitFiveQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitFive->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFiveQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitSixCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitSixCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitSixCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitSix->addChild(drawModelOneSafeOneFrontOneSmallOneDigitFiveCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitSixQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitSixQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitSixQuadrangleOne->texture=LoadTexture("6.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitSixQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitSix->addChild(drawModelOneSafeOneFrontOneSmallOneDigitSixQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitSevenCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitSevenCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitSevenCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitSeven->addChild(drawModelOneSafeOneFrontOneSmallOneDigitSevenCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitSevenQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitSevenQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitSevenQuadrangleOne->texture=LoadTexture("7.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitSevenQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitSeven->addChild(drawModelOneSafeOneFrontOneSmallOneDigitSevenQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitEightCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitEightCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitEightCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitEight->addChild(drawModelOneSafeOneFrontOneSmallOneDigitEightCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitEightQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitEightQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitEightQuadrangleOne->texture=LoadTexture("8.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitEightQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitEight->addChild(drawModelOneSafeOneFrontOneSmallOneDigitEightQuadrangleOne);
  drawCube *drawModelOneSafeOneFrontOneSmallOneDigitNineCubeOne=new drawCube;
  drawModelOneSafeOneFrontOneSmallOneDigitNineCubeOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitNineCubeOne->texture=LoadTexture("12.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitNine->addChild(drawModelOneSafeOneFrontOneSmallOneDigitNineCubeOne);
  drawQuadrangle *drawModelOneSafeOneFrontOneSmallOneDigitNineQuadrangleOne=new drawQuadrangle;
  drawModelOneSafeOneFrontOneSmallOneDigitNineQuadrangleOne->useTexture=true;
  drawModelOneSafeOneFrontOneSmallOneDigitNineQuadrangleOne->texture=LoadTexture("9.bmp",512,512);
  drawModelOneSafeOneFrontOneSmallOneDigitNineQuadrangleOne->location=Vector3(0.0,0.0,0.50001);
  drawModelOneSafeOneFrontOneSmallOneDigitNine->addChild(drawModelOneSafeOneFrontOneSmallOneDigitNineQuadrangleOne);

  drawCube *drawModelOneSafeOneFrontTwoCubeOne=new drawCube;
  drawModelOneSafeOneFrontTwoCubeOne->useTexture=true;
  drawModelOneSafeOneFrontTwoCubeOne->texture=LoadTexture("11.bmp",512,512);
  drawModelOneSafeOneFrontTwo->addChild(drawModelOneSafeOneFrontTwoCubeOne);
  drawCube *drawModelOneSafeOneBackOneCubeOne=new drawCube;
  drawModelOneSafeOneBackOneCubeOne->useTexture=true;
  drawModelOneSafeOneBackOneCubeOne->texture=LoadTexture("10.bmp",512,512);
  drawModelOneSafeOneBackOne->addChild(drawModelOneSafeOneBackOneCubeOne);
  drawCube *drawModelOneSafeOneLeftOneCubeOne=new drawCube;
  drawModelOneSafeOneLeftOneCubeOne->useTexture=true;
  drawModelOneSafeOneLeftOneCubeOne->texture=LoadTexture("10.bmp",512,512);
  drawModelOneSafeOneLeftOne->addChild(drawModelOneSafeOneLeftOneCubeOne);
  drawCube *drawModelOneSafeOneRightOneCubeOne=new drawCube;
  drawModelOneSafeOneRightOneCubeOne->useTexture=true;
  drawModelOneSafeOneRightOneCubeOne->texture=LoadTexture("10.bmp",512,512);
  drawModelOneSafeOneRightOne->addChild(drawModelOneSafeOneRightOneCubeOne);
  drawCube *drawModelOneSafeOneTopOneCubeOne=new drawCube;
  drawModelOneSafeOneTopOneCubeOne->useTexture=true;
  drawModelOneSafeOneTopOneCubeOne->texture=LoadTexture("10.bmp",512,512);
  drawModelOneSafeOneTopOne->addChild(drawModelOneSafeOneTopOneCubeOne);
  drawCube *drawModelOneSafeOneBottomOneCubeOne=new drawCube;
  drawModelOneSafeOneBottomOneCubeOne->useTexture=true;
  drawModelOneSafeOneBottomOneCubeOne->texture=LoadTexture("10.bmp",512,512);
  drawModelOneSafeOneBottomOne->addChild(drawModelOneSafeOneBottomOneCubeOne);
  */
}
