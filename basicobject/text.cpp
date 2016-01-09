//
//  text.cpp
//  mygraphics
//
//  Created by zyhc on 1/9/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#include "text.hpp"
void Text::draw()
{
    glScaled(.05, .05, .05);
    glRasterPos2d(0,0);
    for (int i = 0; i < text.length(); i++) {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
    }    
}