#include "drawla.h"

void drawla::draw()
{
  glPushMatrix();
glutSolidSphere(1,20,20);
  glPopMatrix();
}
