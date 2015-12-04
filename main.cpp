#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include "gluthead.h"
#include "object.hpp"
#include "camera.hpp"

#define defineCheckerImageWidth 64
#define defineCheckerImageHeight 64

int iWindowHandle=0;
GLsizei iWidth=0;
GLsizei iHeight=0;
GLubyte byteCheckerImage[defineCheckerImageHeight][defineCheckerImageWidth][4];
GLuint iTextureName=0;

float fDistance=1.0;
GLfloat fTriangleRotation=0.0;
GLfloat fQuadrangleRotation=0.0;

bool bPersp=true;
bool bWire=false;
bool bAnim=false;
bool bDisplayList=true;

std::vector<Object*> objectList;//main list
Camera mainCamera;

void makeCheckerImageFunction()
{
    for (int i=0;i<defineCheckerImageHeight;i++)
    {
        for (int j=0;j<defineCheckerImageWidth;j++)
        {
            int c=(((i&0x8)==0)^((j&0x8)==0))*255;
            byteCheckerImage[i][j][0]=(GLubyte)c;
            byteCheckerImage[i][j][1]=(GLubyte)c;
            byteCheckerImage[i][j][2]=(GLubyte)c;
            byteCheckerImage[i][j][3]=(GLubyte)255;
        }
    }
}

void initFunction()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
    makeCheckerImageFunction();
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glGenTextures(1,&iTextureName);
    glBindTexture(GL_TEXTURE_2D,iTextureName);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,defineCheckerImageWidth,defineCheckerImageHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,byteCheckerImage);
}

void glutIdleFunction()
{
    // for (int i=0;i<10000000;i++);
    glutPostWindowRedisplay(iWindowHandle);
}

void updateViewFunction(GLsizei width,GLsizei height)
{
    glViewport(0,0,(GLsizei)width,(GLsizei)height); // set view-port
    glMatrixMode(GL_PROJECTION); // select projection matrix
    glLoadIdentity(); // set projection matrix
    
    GLfloat fWidthHeightRatio=(GLfloat)width/(GLfloat)height; // calculate aspect ratio of window
    if (bPersp)
    {
        gluPerspective(60.0,fWidthHeightRatio,0.1,1000.0);
        // glFrustum(-3.0,3.0,-3.0,3.0,0.1,100.0);
    }
    else
    {
        glOrtho(-3.0,3.0,-3.0,3.0,-100.0,100.0);
    }
    glMatrixMode(GL_MODELVIEW); // select model-view matrix
    glLoadIdentity(); // set model-view matrix
}

void glutReshapeFunction(GLsizei width,GLsizei height)
{
    if (height==0) // prevent from dividing by zero
    {
        height=1; // make height equal to one
    }
    iWidth=width;
    iHeight=height;
    updateViewFunction(iWidth,iHeight);
}

void glutKeyboardFunction(unsigned char k,int x,int y)
{
    Object::downKey(k, x, y);
    switch(k)
    {
        case 27:{}
        case 'q':
        {
            exit(0);
            break;
        }
        case 'p':
        {
            bPersp=!bPersp;
            updateViewFunction(iWidth,iHeight);
            break;
        }
        case 'o':
        {
            bWire=!bWire;
            break;
        }
        case ' ':
        {
            bAnim=!bAnim;
            break;
        }
        case 'l':
        {
            bDisplayList=!bDisplayList;
            break;
        }
        default:
        {
            break;
        }
    }
}

void drawObject(Object* obj)
{
    glPushMatrix();
    glColor3f(obj->color.x, obj->color.y, obj->color.z);
    glTranslatef(obj->location.x, obj->location.y, obj->location.z);
    glRotatef(obj->rotate.x, 1, 0, 0);
    glRotatef(obj->rotate.y, 0, 1, 0);
    glRotatef(obj->rotate.z, 0, 0, 1);
    glScalef(obj->size.x, obj->size.y, obj->size.z);
    if (obj->visible)
    {
        obj->draw();
    }
    obj->script();
    for (int i = 0;i<obj->children.size();i++)
    {
        drawObject(obj->children[i]);
    }
    glPopMatrix();
}
void glutDisplayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); // select model-view matrix
    glLoadIdentity(); // set model-view matrix
    
    gluLookAt(mainCamera.location.x,mainCamera.location.y,mainCamera.location.z,mainCamera.center.x,mainCamera.center.y,mainCamera.center.z,0.0,1.0,0.0);
    if (bWire)
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
    for (int i = 0; i<objectList.size(); i++)
    {
        if (objectList[i]->parent == nullptr)
        {
            drawObject(objectList[i]);
        }
        
    }
    //    drawModelFunction();
    
    // getFPS();
    
    glutSwapBuffers();
}
void glutKeyboardReleaseFunction(unsigned char k,int x,int y)
{
    Object::upKey(k,x,y);
}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv); // initialize glut
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH); // set display mode
    glutInitWindowPosition(50,50); // set top-left display window position
    glutInitWindowSize(1200,700); // set display window width and height
    iWindowHandle=glutCreateWindow("Room Escape"); // create display window
    initFunction();
    glutDisplayFunc(glutDisplayFunction); // send graphics to display window
    glutReshapeFunc(glutReshapeFunction);
    glutKeyboardFunc(glutKeyboardFunction);
    glutIdleFunc(glutIdleFunction);
    glutKeyboardUpFunc(glutKeyboardReleaseFunction);
    objectList.push_back(&mainCamera);
    addObject(&objectList);
    glutMainLoop(); // display everything and wait
    return 0;
}
