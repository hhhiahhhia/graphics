//
//  object.hpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 漏 2015 zyhc. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <stdio.h>
#include "gluthead.h"
#include <vector>
#include <string>
using namespace std;
struct Vector3
{
    double x,y,z;
    Vector3():x(0),y(0),z(0){};
    Vector3(double x,double y,double z):x(x),y(y),z(z){}
};
struct VectorList
{
    vector<Vector3> vlist,vtlist,vnlist;
    vector<vector<Vector3> > drawlist;
};
class Object
{
public:
    Vector3 location;
    Vector3 rotate;
    Vector3 size;
    Vector3 color;
    Vector3 highLightColor;
    GLint texture;
    bool isCamera;
    bool isLight;
    bool visible;
    bool useTexture;
    bool disableTexture;
    Object* parent;
    std::vector<Object*> children;
    virtual void script(){}
    virtual void draw(){}
    virtual void clicked(){}
    virtual VectorList exportOBJ(){VectorList v;return v;}
    virtual void shader()
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, texture );
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    }
    virtual void closeShader()
    {
        glDisable(GL_TEXTURE_2D);
    }
    void addChild(Object* newObject)
    {
        children.push_back(newObject);
        newObject->parent = this;
    }
    Object()
    {
        visible = true;
		parent = nullptr;
		location = Vector3(0.0,0.0,0.0);
		rotate = Vector3(0.0,0.0,0.0);
        size = Vector3(1.0,1.0,1.0);
        color = Vector3(-1,-1,-1);
        highLightColor = Vector3(0,0,0);
        isCamera = false;
        isLight = false;
        useTexture = false;
    }
    static bool keyDown[256],mouseClicked,mouseClickedRight;
    static double keyLoc[256][2];
    static double mouseX,mouseY;
    static std::vector<Object*> clickedList;
    static void upKey(unsigned char key,int x,int y);
    static void downKey(unsigned char key,int x,int y);
    static bool keyPushed(unsigned char key);
};
void addObject(std::vector<Object*>*);
GLuint LoadTexture( const char * filename ,int width, int height);
#endif /* object_hpp */
