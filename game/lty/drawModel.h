#ifndef drawModel_h
#define drawModel_h

#include <stdio.h>
#include "../../object.hpp"
#include "drawModel.h"
#include "drawQuadrangle.h"
#include "../../basicobject/cube.hpp"

class Model:public Object
{
public:
  Model();
  virtual void draw();
};
class Key;
class SafeDoor;
class Safe:public Object
{
public:
    Key* iKey;
    SafeDoor *iFrontRight;
  Safe();
  virtual void draw();
    virtual void script();
};
class Digit;
class Key:public Object
{
public:
    bool suc;
    Digit* iDigit[9];
  Key();
  virtual void draw();
    virtual void script();
};
class SafeDoor : public Cube
{
public:
    bool move;
    SafeDoor();
    virtual void script()
    {
        if (move)
        {
            if (location.x >-3)
                location.x -= 0.1;
        }
    }
    
};
class Digit:public Object
{
public:
  int ifmove;
  Digit();
  virtual void draw();
  virtual void clicked()
  {
	ifmove=1-ifmove;
  }
  virtual void script();
};

class DigitCube:public Cube
{
public:
  DigitCube()
  {
	useTexture=true;
	texture=LoadTexture("12.bmp",512,512);
  }
  // virtual void draw();
};

class DigitQuadrangle:public Cube
{
public:
    virtual void shader()
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, texture );
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_TEXTURE_MAG_FILTER);
    }
  DigitQuadrangle()
  {
      size = Vector3(1,1,0.1);
      rotate = Vector3(0,0,270);
	useTexture=true;
	location=Vector3(0.0,0.0,0.50001);
  }
  // virtual void draw();
};

#endif
