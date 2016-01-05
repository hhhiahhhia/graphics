#ifndef Top_h
#define Top_h

#include <stdio.h>
#include "../../object.hpp"

class Top:public Object
{
  public:
     virtual void draw();
     Top(){
     	useTexture = true;
        texture = LoadTexture("wall4.bmp", 512 , 512);
     }
};

#endif
