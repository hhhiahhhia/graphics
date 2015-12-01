//
//  triangle.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "triangle.hpp"
void Triangle::draw()
{
    glBegin(GL_TRIANGLES);
    
//    glColor3f(1.0,0.0,0.0); // front
    glVertex3f(0.0,1.0,0.0);
//    glColor3f(0.0,1.0,0.0); // green
    glVertex3f(-1.0,-1.0,1.0);
//    glColor3f(0.0,0.0,1.0); // blue
    glVertex3f(1.0,-1.0,1.0);
    
//    glColor3f(1.0,0.0,0.0); // right
    glVertex3f(0.0,1.0,0.0);
//    glColor3f(0.0,0.0,1.0); // blue
    glVertex3f(1.0,-1.0,1.0);
//    glColor3f(0.0,1.0,0.0); // green
    glVertex3f(1.0,-1.0,-1.0);
    
//    glColor3f(1.0,0.0,0.0); // back
    glVertex3f(0.0,1.0,0.0);
//    glColor3f(0.0,1.0,0.0); // green
    glVertex3f(1.0,-1.0,-1.0);
//    glColor3f(0.0,0.0,1.0); // blue
    glVertex3f(-1.0,-1.0,-1.0);
    
//    glColor3f(1.0,0.0,0.0); // left
    glVertex3f(0.0,1.0,0.0);
//    glColor3f(0.0,0.0,1.0); // blue
    glVertex3f(-1.0,-1.0,-1.0);
//    glColor3f(0.0,1.0,0.0); // green
    glVertex3f(-1.0,-1.0,1.0);
    glEnd();

}