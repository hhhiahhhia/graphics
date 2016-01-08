#ifndef NewWall_h
#define NewWall_h

#include <stdio.h>
#include "../../basicobject/cube.hpp"

class NewWall:public Cube
{
  public:
     NewWall(){
     	useTexture = true;
        texture = LoadTexture("wall11.bmp", 512 , 512);
     }
};

#endif
