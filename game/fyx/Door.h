#ifndef Door_h
#define Door_h

#include <stdio.h>
#include "../../basicobject/cube.hpp"

class Door:public Cube
{
  public:
     Door(){
     	useTexture = true;
        texture = LoadTexture("door.bmp", 512 , 512);
     }
};

#endif
