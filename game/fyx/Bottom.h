#ifndef Bottom_h
#define Bottom_h

#include <stdio.h>
#include "../../object.hpp"

class Bottom:public Object
{
  public:
     virtual void draw();
     Bottom(){
     	  useTexture = true;
        texture = LoadTexture("wall7.bmp", 512 , 512);
     }
};

#endif
