#include "drawWallLeft.h"

void drawWallLeft::draw()
{
  glPushMatrix();
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(0.0,100.0,0.0);
  glVertex3f(0.0,100.0,-100.0);
  glVertex3f(0.0,0.0,-100.0);
  glVertex3f(0.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}
