#include "drawWallFront.h"

void drawWallFront::draw()
{
  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
  glVertex3f(100.0,100.0,0.0);
  glVertex3f(0.0,100.0,0.0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(100.0,0.0,0.0);
  glEnd();
  glPopMatrix();
}