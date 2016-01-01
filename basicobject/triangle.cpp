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
    
    glTexCoord2f( 0,1);
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f( 0,0);
    glVertex3f(-1.0,-1.0,1.0);
    glTexCoord2f( 1,0 );
    glTexCoord2f( 0,1 );
    glVertex3f(1.0,-1.0,1.0);
    
    glTexCoord2f( 0,1);
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f( 0,0);
    glVertex3f(1.0,-1.0,1.0);
    glTexCoord2f( 1,0 );
    glTexCoord2f( 0,1 );
    glVertex3f(1.0,-1.0,-1.0);
    
    glTexCoord2f( 0,1);
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f( 0,0);
    glVertex3f(1.0,-1.0,-1.0);
    glTexCoord2f( 1,0 );
    glTexCoord2f( 0,1 );
    glVertex3f(-1.0,-1.0,-1.0);
    
    glTexCoord2f( 0,1);
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f( 0,0);
    glVertex3f(-1.0,-1.0,-1.0);
    glTexCoord2f( 1,0 );
    glTexCoord2f( 0,1 );
    glVertex3f(-1.0,-1.0,1.0);
    glEnd();
//    glutSolidTeapot(1);

}