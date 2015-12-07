#include "drawQuadrangle.h"

void drawQuadrangle::draw()
{
  glPushMatrix();
  glBegin(GL_QUADS);
  glVertex3f(1.0,1.0,0.0);
  glVertex3f(-1.0,1.0,0.0);
  glVertex3f(-1.0,-1.0,0.0);
  glVertex3f(1.0,-1.0,0.0);
  glEnd();
  glPopMatrix();
}
