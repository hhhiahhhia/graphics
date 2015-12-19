#ifndef drawx_h
#define drawx_h

#include <stdio.h>
#include "../../object.hpp"

class drawx:public Object
{
public:
  virtual void draw();
};

#endif
