#ifndef MyCylinder_h
#define MyCylinder_h

#include <stdio.h>
#include "../../object.hpp"

class MyCylinder:public Object
{
  virtual void script();
  virtual void draw();
};

void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments);

#endif
