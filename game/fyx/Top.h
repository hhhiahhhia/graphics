#ifndef Top_h
#define Top_h

#include <stdio.h>
#include "../../basicobject/cube.hpp"

class Top:public Cube
{
  public:
     Top(){
     	useTexture = true;
        texture = LoadTexture("top1.bmp", 512 , 512);
     }
};

#endif
