#ifndef NewWall_h
#define NewWall_h

#include <stdio.h>
#include "../../object.hpp"

class NewWall:public Object
{
  public:
     virtual void draw();
     NewWall(){
     	useTexture = true;
        texture = LoadTexture("wall6.bmp", 512 , 512);
     }
};

#endif
