#include "drawQuadrangle.h"


void Quadrangle::draw()
{
  glPushMatrix();
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2d(1,1);
  glVertex3f(0.5,0.5,0.0);
    glNormal3f(0, 0, 1);
    glTexCoord2d(-1,1);
  glVertex3f(-0.5,0.5,0.0);
    glNormal3f(0, 0, 1);
    glTexCoord2d(-1,-1);
    
  glVertex3f(-0.5,-0.5,0.0);
    glNormal3f(0, 0, 1);
    glTexCoord2d(1,-1);
  glVertex3f(0.5,-0.5,0.0);
  glEnd();
  glPopMatrix();
}
