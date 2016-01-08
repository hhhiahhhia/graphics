#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "gluthead.h"
#include "object.hpp"
#include "basicobject/camera.hpp"
#include "basicobject/light.hpp"

#define PICK_TOL 5
#define PICK_BUFFER_SIZE 256
unsigned int PickBuffer[PICK_BUFFER_SIZE];
int RenderMode;



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
std::vector<Object*> clickList;
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
        gluPerspective(45.0,fWidthHeightRatio,0.1,1000.0);
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
    static bool flag = false;
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

void drawObject(Object* obj,Vector3 defaultColor)
{
    glPushMatrix();
    if (obj->location.x == 50)
    {
        obj->location.x = 50;
    }
    if (obj->color.x != -1)
    {
        defaultColor = obj->color;
    }
    if (obj->isLight == false)
    {
        float ambient[4];
        float diffuse[4];
        float specular[4];
        // color part
        
        
        ambient[0] = defaultColor.x;
        ambient[1] = defaultColor.y;
        ambient[2] = defaultColor.z;
        ambient[3] = 1.0f;
        diffuse[0] = defaultColor.x;
        diffuse[1] = defaultColor.y;
        diffuse[2] = defaultColor.z;
        diffuse[3] = 1.0f;
        specular[0] = obj->highLightColor.x;
        specular[1] = obj->highLightColor.y;
        specular[2] = obj->highLightColor.z;
        specular[3] = 1.0f;
        
        //        GLfloat emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat shininess  = 40.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT,   ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  specular);
        //        glMaterialfv(GL_FRONT, GL_EMISSION,  emission);
        glMaterialf (GL_FRONT, GL_SHININESS, shininess);
        glColor3f(defaultColor.x, defaultColor.y, defaultColor.z);
    }
    //
    glTranslatef(obj->location.x, obj->location.y, obj->location.z);
    glRotatef(obj->rotate.x, 1, 0, 0);
    glRotatef(obj->rotate.y, 0, 1, 0);
    glRotatef(obj->rotate.z, 0, 0, 1);
    glScalef(obj->size.x, obj->size.y, obj->size.z);
    
    if (obj->isLight)
    {
        float position[4] = {0,0,0,1};
        GLfloat ambient[4];
        float diffuse[4];
        float specular[4];
        float attenuation[3];
        Light *light = dynamic_cast<Light*>(obj);
        ambient[0] = light->ambient.x;
        ambient[1] = light->ambient.y;
        ambient[2] = light->ambient.z;
        ambient[3] = 1;
        diffuse[0] = light->diffuse.x;
        diffuse[1] = light->diffuse.y;
        diffuse[2] = light->diffuse.z;
        diffuse[3] = 1;
        specular[0] = light->specular.x;
        specular[1] = light->specular.y;
        specular[2] = light->specular.z;
        specular[3] = 1;
        attenuation[0] = light->attenuation.x;
        attenuation[1] = light->attenuation.y;
        attenuation[2] = light->attenuation.z;
        
        glLightfv(light->usedLight, GL_POSITION, position);
        glLightfv(light->usedLight, GL_AMBIENT,  ambient);
        glLightfv(light->usedLight, GL_DIFFUSE,  diffuse);
        glLightfv(light->usedLight, GL_SPECULAR,  specular);
        glLightfv(light->usedLight, GL_CONSTANT_ATTENUATION, attenuation);
        if (light->open) glEnable(light->usedLight);
        else
        {
            glDisable(light->usedLight);
        }
        
    }
    glPushAttrib(GL_TEXTURE_BIT);
    if (obj->visible)
    {
        if (obj->useTexture)
        {
            obj->shader();
        }
        glPushName( clickList.size() );
        clickList.push_back(obj);
        obj->draw();
        glPopName();
    }
    
    for (int i = 0;i<int(obj->children.size());i++)
    {
        drawObject(obj->children[i],defaultColor);
    }
    obj->closeShader();
    glPopAttrib();
    glPopMatrix();
}
void runObjectScript(Object* obj)
{
    obj->script();
    for (int i = 0;i<int(obj->children.size());i++)
    {
        runObjectScript(obj->children[i]);
    }
}
void glutDisplayFunction()
{
    if( RenderMode == GL_SELECT )
    
    {
        int viewport[4];
        glMatrixMode(GL_PROJECTION); //保存投影矩阵
        glPushMatrix();
        glLoadIdentity();
        int dx = glutGet( GLUT_WINDOW_WIDTH );
        
        int dy = glutGet( GLUT_WINDOW_HEIGHT );
        glGetIntegerv(GL_VIEWPORT,viewport);
        
        gluPickMatrix( (double)Object::mouseX, (double)(dy - Object::mouseY),
                      
                      PICK_TOL, PICK_TOL, viewport );
        gluPerspective(45,(GLfloat)dx/(GLfloat)dy,0.1,1000);
        glInitNames();
        
        
    }
//    else
//    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW); // select model-view matrix
        glLoadIdentity(); // set model-view matrix
//    }
    gluLookAt(mainCamera.location.x,mainCamera.location.y,mainCamera.location.z,mainCamera.center.x,mainCamera.center.y,mainCamera.center.z,0.0,1.0,0.0);
    glPushMatrix();
    glEnable(GL_LIGHTING); //在后面的渲染中使用光照
    glEnable(GL_DEPTH_TEST);

    
    glPopMatrix();
    if (bWire)
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
    clickList.erase(clickList.begin(),clickList.end());
    for (int i = 0; i<int(objectList.size()); i++)
    {
        if (objectList[i]->parent == nullptr)
        {
            drawObject(objectList[i],Vector3(0.7,0.7,0.7));
        }
        
    }
    for (int i = 0; i<int(objectList.size()); i++)
    {
        if (objectList[i]->parent == nullptr)
        {
            runObjectScript(objectList[i]);
        }
        
    }
    //    drawModelFunction();
    
    // getFPS();
    if (RenderMode == GL_RENDER)
        glutSwapBuffers();
    else
    {
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glFlush();
    }
    
}
void glutKeyboardReleaseFunction(unsigned char k,int x,int y)
{
    Object::upKey(k,x,y);
    Object::clickedList.erase(Object::clickedList.begin(),Object::clickedList.end());
}
void glutMousefunction(int button, int state,
                       int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
        {
            if (state == GLUT_DOWN)
            {
                Object::mouseClicked = true;
                RenderMode = GL_SELECT;
                
                glRenderMode( GL_SELECT );
                
                glutDisplayFunction();
                
                
                
                
                RenderMode = GL_RENDER;
                
                int Nhits = glRenderMode( GL_RENDER );
                
//                fprintf( stderr, "# pick hits = %d\n", Nhits );
                int nitems,zmin,zmax;
                for( int i = 0,index = 0; i < Nhits; i++ )
                
                {
                    nitems = PickBuffer[index++];
                    
                    zmin = PickBuffer[index++];
                    
                    zmax = PickBuffer[index++];
//                    fprintf( stderr,
//                            
//                            "Hit # %2d: found %2d items on the name stack/n",
//                            
//                            i, nitems );
//                    
//                    
//                    fprintf( stderr, "/tZmin = 0x%0x, Zmax = 0x%0x/n",
//                            
//                            zmin, zmax );
                   
                    for( int j = 0; j < nitems; j++ )
                    
                    {
                        
                        int item = PickBuffer[index++];
                        if (i == Nhits -1)
                        {
                            Object* obj = clickList[item];
                            Object::clickedList.push_back(obj);
                            while (obj->parent!=nullptr)
                            {
                                obj->clicked();
                                obj = obj->parent;
                                Object::clickedList.push_back(obj);
                            }
                            obj->clicked();

                            
                        }
                        
                    }
                    
                }
                
//                ActiveButton &= ~LEFT;
//                
//                glutSetWindow( GrWindow );
                
                glutPostRedisplay();
                
            }
            else
            {
                Object::mouseClicked = false;
            }
        }
        case GLUT_RIGHT_BUTTON:
        {
            if (state == GLUT_DOWN)
            {
                Object::mouseClickedRight = true;
            }
            else
            {
                Object::mouseClickedRight = false;
            }
        }
            
    }
}
void glutMouseMove(int x, int y )
{
    Object::mouseX = GLfloat( x );
    Object::mouseY = GLfloat( y );
}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv); // initialize glut
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH); // set display mode
    glutInitWindowPosition(100,100); // set top-left display window position
    glutInitWindowSize(1200,700); // set display window width and height
    iWindowHandle=glutCreateWindow("Room Escape"); // create display window
    initFunction();
    glutDisplayFunc(glutDisplayFunction); // send graphics to display window
    glutReshapeFunc(glutReshapeFunction);
    glutKeyboardFunc(glutKeyboardFunction);
    glutIdleFunc(glutIdleFunction);
    glutKeyboardUpFunc(glutKeyboardReleaseFunction);
    glutMouseFunc(glutMousefunction);
    glutPassiveMotionFunc( glutMouseMove );
    glutMotionFunc( glutMouseMove );
    objectList.push_back(&mainCamera);
    addObject(&objectList);
    RenderMode = GL_RENDER;
    glSelectBuffer( PICK_BUFFER_SIZE, PickBuffer );
    glutMainLoop(); // display everything and wait
    return 0;
}
