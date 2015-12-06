#include "drawCube.h"

void drawCube::draw()
{
  glPushMatrix();
  glutSolidCube(1.0);
  glPopMatrix();
}
