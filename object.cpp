//
//  object.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "object.hpp"
#include "stdlib.h"
#include "game/lyt/lyt.hpp"
#include "game/zyh/zyh.hpp"
#include "game/lty/lty.hpp"
#include "game/xft/xft.hpp"
#include "game/fyx/fyx.hpp"
bool Object::keyDown[256],Object::mouseClicked,Object::mouseClickedRight;
double Object::keyLoc[256][2];
double Object::mouseX,Object::mouseY;
std::vector<Object*> Object::clickedList;
Object::Object()
{
    visible = true;
    parent = nullptr;
    isLight = false;
    isCamera = false;
    useTexture = false;
    disableTexture = false;
    location = Vector3(0.0,0.0,0.0);
    rotate = Vector3(0.0,0.0,0.0);
    size = Vector3(1.0,1.0,1.0);
    color = Vector3(-1,-1,-1);
    highLightColor = Vector3(0,0,0);
}
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
GLuint LoadTexture( const char * filename,int w,int h)
{
    
    GLuint texture;
    int width;
    int height;
    unsigned char * data;
    
    FILE * file;
    
    file = fopen( filename, "rb" );
    
    if ( file == NULL ) return 0;
    
    int offset = 0;
    fseek(file, 10L, SEEK_SET);
    fread(&offset, sizeof(char), 4, file);
    fseek(file, 18L, SEEK_SET);
    fread(&width, sizeof(char), 4, file);
    fseek(file, 22L, SEEK_SET);
    fread(&height, sizeof(char), 4, file);
//    fseek(file, 0L, SEEK_SET);
//    unsigned char *fp_temp;
//    fp_temp=(unsigned char*)malloc(offset);
//    fread(file, 1, offset, file);
    fseek(file, offset, SEEK_SET);
    data = new unsigned char [ width * height * 3 ];
//    int stride=(24*width+31)/8;
//    stride=stride/4*4;
    fread( data, width * height * 3, 1, file );
    fclose( file );
//    for (int i = 0 ;i <(width*height*3)/2;++i)
//    {
//        unsigned char t;
//        t = data[i];
//        data[i] = data[width*height*3-i-1];
//        data[width*height*3 - i -1] = t;
//    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Min Filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
//    
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
//    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

    delete []data;
    glBindTexture( GL_TEXTURE_2D, 0 );
    return texture;
}
