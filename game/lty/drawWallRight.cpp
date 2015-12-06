#include "drawWallRight.h"

void drawWallRight::draw()
{
  glPushMatrix();
  glBegin(GL_QUADS);
  glVertex3f(100.0,100.0,-100.0);
  glVertex3f(100.0,100.0,0.0);
  glVertex3f(100.0,0.0,0.0);
  glVertex3f(100.0,0.0,-100.0);
  glEnd();
  glPopMatrix();
}
