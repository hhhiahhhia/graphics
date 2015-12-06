#ifndef drawModel_h
#define drawModel_h

#include <stdio.h>
#include "../../object.hpp"

class drawModel:public Object
{
public:
  virtual void draw();
};

#endif
