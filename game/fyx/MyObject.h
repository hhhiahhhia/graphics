#ifndef MyObject_h
#define MyObject_h

#include <stdio.h>
#include "../../object.hpp"

class MyObject:public Object
{
  public:
     virtual void draw();
};

#endif
