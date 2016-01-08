//
//  object.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "object.hpp"
#include "game/lyt/lyt.hpp"
#include "game/zyh/zyh.hpp"
#include "game/lty/lty.hpp"
#include "game/xft/xft.hpp"
#include "game/fyx/fyx.hpp"
bool Object::keyDown[256],Object::mouseClicked,Object::mouseClickedRight;
double Object::keyLoc[256][2];
double Object::mouseX,Object::mouseY;
std::vector<Object*> Object::clickedList;
void Object::upKey(unsigned char key,int x,int y)
{
    keyDown[key] = false;
}
void Object::downKey(unsigned char key,int x,int y)
{
    keyDown[key] = true;
    keyLoc[key][0] = x;
    keyLoc[key][1] = y;
}
bool Object::keyPushed(unsigned char key)
{
    return keyDown[key];
}
void addObject(std::vector<Object*>* objectList)
{
    ltyPart(objectList);
    zyhPart(objectList);
    lytPart(objectList);
    xftPart(objectList);
    fyxPart(objectList);
}
GLuint LoadTexture( const char * filename ,int width, int height)
{
    
    GLuint texture;
    
    unsigned char * data;
    
    FILE * file;
    
    file = fopen( filename, "rb" );
    
    if ( file == NULL ) return 0;
    data = new unsigned char [ width * height * 3 ];
    //int size = fseek(file,);
    fread( data, width * height * 3, 1, file );
    fclose( file );
    for (int i = 0 ;i <(width*height*3)/2;++i)
    {
        unsigned char t;
        t = data[i];
        data[i] = data[width*height*3-i-1];
        data[width*height*3 - i -1] = t;
    }
    
    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    delete []data;
    glBindTexture( GL_TEXTURE_2D, 0 );
    return texture;
}
