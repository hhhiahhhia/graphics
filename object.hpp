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
struct Vector3
{
    double x,y,z;
    Vector3():x(0),y(0),z(0){};
    Vector3(double x,double y,double z):x(x),y(y),z(z){}
};
class Object
{
public:
    Vector3 location;
    Vector3 rotate;
    Vector3 size;
    Vector3 color;
	bool bLocationFlag;
	bool bRotateFlag;
	bool bSizeFlag;
	bool bColorFlag;
    bool isCamera;
    bool visible;
    Object* parent;
    std::vector<Object*> children;
    virtual void script(){}
    virtual void draw(){}
    virtual void clicked(){}
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
        color = Vector3(0.0,0.0,0.0);
		bLocationFlag = false;
		bRotateFlag = false;
		bSizeFlag = false;
		bColorFlag = false;
    }
    static bool keyDown[256],mouseClicked,mouseClickedRight;
    static double keyLoc[256][2];
    static double mouseX,mouseY;
    static void upKey(unsigned char key,int x,int y);
    static void downKey(unsigned char key,int x,int y);
    static bool keyPushed(unsigned char key);
};
void addObject(std::vector<Object*>*);
#endif /* object_hpp */
