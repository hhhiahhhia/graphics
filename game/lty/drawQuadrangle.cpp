#include "drawQuadrangle.h"

void drawQuadrangle::draw()
{
  glPushMatrix();
  glBegin(GL_QUADS);
  glTexCoord2f( 1, 1 );
  glVertex3f(1.0,1.0,0.0);
   glTexCoord2f( 0.0, 1.0 );
  glVertex3f(-1.0,1.0,0.0);
  glTexCoord2f( 0.0, 0.0 );
  glVertex3f(-1.0,-1.0,0.0);
    glTexCoord2f( 1.0, 0.0 );
  glVertex3f(1.0,-1.0,0.0);
  glEnd();
  glPopMatrix();
}
