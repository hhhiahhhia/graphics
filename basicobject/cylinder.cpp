//
//  cylinder.cpp
//  graphics
//
//  Created by 逸婷 李 on 16/1/8.
//  Copyright (c) 2016年 逸婷 李. All rights reserved.
//
#include <math.h>
#include "cylinder.h"

GLvoid DrawCircle(float cx, float cy, float cz, float r, int num_segments)
{
    GLfloat vertex[4];
    
    const GLfloat delta_angle = 2.0*M_PI/num_segments;
    glBegin(GL_TRIANGLE_FAN);
    
    vertex[0] = cx;
    vertex[1] = cy;
    vertex[2] = cz;
    vertex[3] = 1.0;
    glVertex4fv(vertex);
    
    //draw the vertex on the contour of the circle
    for(int i = 0; i < num_segments ; i++)
    {
        vertex[0] = cos(delta_angle*i) * r + cx;
        vertex[1] = sin(delta_angle*i) * r + cy;
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

Cylinder::Cylinder(double _base, double _top,double _height,bool _ifTopCircle,bool _ifBaseCircle){
    
    base=_base;
    top=_top;
    height=_height;
    ifTopCircle=_ifTopCircle;
    ifBaseCircle=_ifBaseCircle;
    rotate.x=90;
    
}

void Cylinder::draw(){
    
    GLUquadricObj *Cylinder1 = gluNewQuadric();
    gluCylinder(Cylinder1, base, top, height, 32, 5);

    if (ifTopCircle){
        DrawCircle(0.0, 0.0, height, top, 32);//top
    }
    if(ifBaseCircle){
        DrawCircle(0.0, 0.0, 0.0, base, 32);//base
    }
}

