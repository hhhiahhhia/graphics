#ifndef Bottom_h
#define Bottom_h

#include <stdio.h>
#include "../../basicobject/cube.hpp"

class Bottom:public Cube
{
  public:
     Bottom(){
     	useTexture = true;
        texture = LoadTexture("floor1.bmp", 512 , 512);
     }
};

#endif
