#include "drawModel.h"
#include "drawQuadrangle.h"
#include "../../basicobject/cube.hpp"

SafeDoor::SafeDoor()
{
    move = false;
};
Model::Model()
{
  Safe *iSafe=new Safe;
  iSafe->location=Vector3(85.0,0.0,-85.0);
  addChild(iSafe);
}

void Model::draw()
{
  glPushMatrix();
  glPopMatrix();
}
void Safe::script() {
    if (iKey->suc)
    {
        iFrontRight->move = 1;
    }
}
Safe::Safe()
{
  iKey=new Key;
  addChild(iKey);

  Cube *iFrontLeft=new Cube;
  iFrontLeft->useTexture=true;
  iFrontLeft->texture=LoadTexture("10.bmp",512,512);
  iFrontLeft->location=Vector3(-4.75,10.0,9.5);
  iFrontLeft->size=Vector3(9.5,18,1.0);
  addChild(iFrontLeft);

    iFrontRight=new SafeDoor;
  iFrontRight->useTexture=true;
  iFrontRight->texture=LoadTexture("10.bmp",512,512);
  iFrontRight->location=Vector3(4.75,10.0,8.5);
  iFrontRight->size=Vector3(9.5,18,1.0);
  addChild(iFrontRight);

  Cube *iBack=new Cube;
  iBack->useTexture=true;
  iBack->texture=LoadTexture("10.bmp",512,512);
  iBack->location=Vector3(0.0,10.0,-9.5);
  iBack->size=Vector3(20.0,20.0,1.0);
  addChild(iBack);

  Cube *iLeft=new Cube;
  iLeft->useTexture=true;
  iLeft->texture=LoadTexture("10.bmp",512,512);
  iLeft->location=Vector3(-10.0,10.0,0.0);
  iLeft->size=Vector3(1.0,20.0,20.0);
  addChild(iLeft);

  Cube *iRight=new Cube;
  iRight->useTexture=true;
  iRight->texture=LoadTexture("10.bmp",512,512);
  iRight->location=Vector3(10.0,10.0,0.0);
  iRight->size=Vector3(1.0,20.0,20.0);
  addChild(iRight);

  Cube *iTop=new Cube;
  iTop->useTexture=true;
  iTop->texture=LoadTexture("10.bmp",512,512);
  iTop->location=Vector3(0.0,19.5,0.0);
  iTop->size=Vector3(20.0,1.0,20.0);
  addChild(iTop);

  Cube *iBottom=new Cube;
  iBottom->useTexture=true;
  iBottom->texture=LoadTexture("10.bmp",512,512);
  iBottom->location=Vector3(0.0,0.5,0.0);
  iBottom->size=Vector3(20.0,1.0,20.0);
  addChild(iBottom);
}

void Safe::draw()
{
  glPushMatrix();
  glPopMatrix();
}
void Key::script(){
    if (iDigit[7]->ifmove && iDigit[2]->ifmove)
    {
        int sum = 0;
        for (int i=1;i<=9;i++)
        {
            sum+=iDigit[i]->ifmove;
        }
        if (sum ==2)
        {
            suc = true;
        }
        else
        {
            suc = false;
        }
    }
    else
    {
        suc = false;
    }
}
Key::Key():suc(false)
{
    iDigit[1]=new Digit;
    iDigit[1]->location=Vector3(-7.0,11.0,10.0);
    addChild(iDigit[1]);
    DigitCube *iDigitCubeOne=new DigitCube;
    iDigit[1]->addChild(iDigitCubeOne);
    DigitQuadrangle *iDigitQuadrangleOne=new DigitQuadrangle;
    iDigitQuadrangleOne->texture=LoadTexture("1.bmp",512,512);
    iDigit[1]->addChild(iDigitQuadrangleOne);
    
    iDigit[2]=new Digit;
    iDigit[2]->location=Vector3(-6.0,11.0,10.0);
    addChild(iDigit[2]);
    DigitCube *iDigitCubeTwo=new DigitCube;
    iDigit[2]->addChild(iDigitCubeTwo);
    DigitQuadrangle *iDigitQuadrangleTwo=new DigitQuadrangle;
    iDigitQuadrangleTwo->texture=LoadTexture("2.bmp",512,512);
    iDigit[2]->addChild(iDigitQuadrangleTwo);
    
    iDigit[3]=new Digit;
    iDigit[3]->location=Vector3(-5.0,11.0,10.0);
    addChild(iDigit[3]);
    DigitCube *iDigitCubeThree=new DigitCube;
    iDigit[3]->addChild(iDigitCubeThree);
    DigitQuadrangle *iDigitQuadrangleThree=new DigitQuadrangle;
    iDigitQuadrangleThree->texture=LoadTexture("3.bmp",512,512);
    iDigit[3]->addChild(iDigitQuadrangleThree);
    
    iDigit[4]=new Digit;
    iDigit[4]->location=Vector3(-7.0,10.0,10.0);
    addChild(iDigit[4]);
    DigitCube *iDigitCubeFour=new DigitCube;
    iDigit[4]->addChild(iDigitCubeFour);
    DigitQuadrangle *iDigitQuadrangleFour=new DigitQuadrangle;
    iDigitQuadrangleFour->texture=LoadTexture("4.bmp",512,512);
    iDigit[4]->addChild(iDigitQuadrangleFour);
    
    iDigit[5]=new Digit;
    iDigit[5]->location=Vector3(-6.0,10.0,10.0);
    addChild(iDigit[5]);
    DigitCube *iDigitCubeFive=new DigitCube;
    iDigit[5]->addChild(iDigitCubeFive);
    DigitQuadrangle *iDigitQuadrangleFive=new DigitQuadrangle;
    iDigitQuadrangleFive->texture=LoadTexture("5.bmp",512,512);
    iDigit[5]->addChild(iDigitQuadrangleFive);
    
    iDigit[6]=new Digit;
    iDigit[6]->location=Vector3(-5.0,10.0,10.0);
    addChild(iDigit[6]);
    DigitCube *iDigitCubeSix=new DigitCube;
    iDigit[6]->addChild(iDigitCubeSix);
    DigitQuadrangle *iDigitQuadrangleSix=new DigitQuadrangle;
    iDigitQuadrangleSix->texture=LoadTexture("6.bmp",512,512);
    iDigit[6]->addChild(iDigitQuadrangleSix);
    
    iDigit[7]=new Digit;
    iDigit[7]->location=Vector3(-7.0,9.0,10.0);
    addChild(iDigit[7]);
    DigitCube *iDigitCubeSeven=new DigitCube;
    iDigit[7]->addChild(iDigitCubeSeven);
    DigitQuadrangle *iDigitQuadrangleSeven=new DigitQuadrangle;
    iDigitQuadrangleSeven->texture=LoadTexture("7.bmp",512,512);
    iDigit[7]->addChild(iDigitQuadrangleSeven);
    
    iDigit[8]=new Digit;
    iDigit[8]->location=Vector3(-6.0,9.0,10.0);
    addChild(iDigit[8]);
    DigitCube *iDigitCubeEight=new DigitCube;
    iDigit[8]->addChild(iDigitCubeEight);
    DigitQuadrangle *iDigitQuadrangleEight=new DigitQuadrangle;
    iDigitQuadrangleEight->texture=LoadTexture("8.bmp",512,512);
    iDigit[8]->addChild(iDigitQuadrangleEight);
    
    iDigit[9]=new Digit;
    iDigit[9]->location=Vector3(-5.0,9.0,10.0);
    addChild(iDigit[9]);
    DigitCube *iDigitCubeNine=new DigitCube;
    iDigit[9]->addChild(iDigitCubeNine);
    DigitQuadrangle *iDigitQuadrangleNine=new DigitQuadrangle;
    iDigitQuadrangleNine->texture=LoadTexture("9.bmp",512,512);
    iDigit[9]->addChild(iDigitQuadrangleNine);
}

void Key::draw()
{
  glPushMatrix();
  glPopMatrix();
}

Digit::Digit()
{
  ifmove=0;
}

void Digit::draw()
{
  glPushMatrix();
  glPopMatrix();
}

void Digit::script()
{
  if (ifmove)
  {
	location.z=9.5;
  }
  else
  {
	location.z=10.0;
  }
}
