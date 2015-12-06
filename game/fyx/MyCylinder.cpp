#include "MyCylinder.h"
#include <math.h>
#include <algorithm>

int PI = 3.141592653;

void MyCylinder::script()
{
	if(location.z >= -97 && location.z <= -3){
		if (keyPushed('-'))
		{		
			location.z -= 0.1;
			rotate.x += 6.0 / PI;
		}
		if (keyPushed('='))
		{			
			location.z += 0.1;
			rotate.x -= 6.0 / PI;
		}
	}
}

void MyCylinder::draw()
{
    GLUquadricObj *Cylinder1 = gluNewQuadric();
  
    glPushMatrix(); 
	glColor3f(0.0, 0.5, 0.9);
	gluCylinder(Cylinder1, 3.0, 3.0, 10.0, 32, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.8, 0.2, 1.0);
	DrawCircleArea(0.0, 0.0, 10.0, 3.0, 32);//top  
    DrawCircleArea(0.0, 0.0, 0.0, 3.0, 32);//base
	glPopMatrix();

}

void DrawCircleArea(float cx, float cy, float cz, float r, int num_segments)
{
	GLfloat vertex[4];
	int PI = 3.141592653;
	const GLfloat delta_angle = 2.0*PI / num_segments;
	glBegin(GL_TRIANGLE_FAN);

	vertex[0] = cx;
	vertex[1] = cy;
	vertex[2] = cz;
	vertex[3] = 1.0;
	glVertex4fv(vertex);

	//draw the vertex on the contour of the circle  
	for (int i = 0; i < num_segments; i++)
	{
		vertex[0] = std::cos(delta_angle*i) * r + cx;
		vertex[1] = std::sin(delta_angle*i) * r + cy;
		vertex[2] = cz;
		vertex[3] = 1.0;
		glVertex4fv(vertex);
	}

	vertex[0] = 1.0 * r + cx;
	vertex[1] = 0.0 * r + cy;
	vertex[2] = cz;
	vertex[3] = 1.0;
	glVertex4fv(vertex);
	glEnd();
}
