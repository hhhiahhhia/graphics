#ifndef drawCube_h
#define drawCube_h

#include <stdio.h>
#include "../../object.hpp"
#include "../../basicobject/cube.hpp"

class drawCube:public Cube
{
public:
  drawCube()
  {
	size=Vector3(1.0,1.0,1.0);
  }
};

#endif
