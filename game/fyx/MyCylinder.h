#ifndef MyCylinder_h
#define MyCylinder_h

#include <stdio.h>
#include "../../object.hpp"

class MyCylinder:public Object
{
public:
  virtual void script();
  virtual void draw();
  bool bSign;
  MyCylinder(){ bSign = true; }
};

void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments);

#endif
