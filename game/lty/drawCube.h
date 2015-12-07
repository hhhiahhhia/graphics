#ifndef drawCube_h
#define drawCube_h

#include <stdio.h>
#include "../../object.hpp"

class drawCube:public Object
{
public:
  virtual void draw();
  drawCube()
  {
	bSizeFlag=true;
	size=Vector3(2.0,2.0,2.0);
  }
};

#endif
