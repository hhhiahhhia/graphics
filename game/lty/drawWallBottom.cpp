#include "drawWallBottom.h"

extern GLuint iTextureName;

void drawWallBottom::draw()
{
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
  glBindTexture(GL_TEXTURE_2D,iTextureName);
  // glColor3f(1.0,0.0,1.0);
  glBegin(GL_QUADS);
  glTexCoord2f(1.0,1.0);
  glVertex3f(100.0,0.0,0.0);
  glTexCoord2f(0.0,1.0);
  glVertex3f(0.0,0.0,0.0);
  glTexCoord2f(0.0,0.0);
  glVertex3f(0.0,0.0,-100.0);
  glTexCoord2f(1.0,0.0);
  glVertex3f(100.0,0.0,-100.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}
