//
//  importedobj.cpp
//  mygraphics
//
//  Created by zyhc on 1/9/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#include "importedobj.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
ImportedObj::ImportedObj(string filename)
{
    vector<Vector3> v,vt,vn;
    vector<GLfloat> rv,rvt,rvn;
    fstream objFile(filename);
    if (!objFile) {
        printf("no such obj\n");
        return;
    }
    vnFlag = false;vtFlag = false;
    v.push_back(Vector3(0,0,0));
    vn.push_back(Vector3(0,0,0));
    vt.push_back(Vector3(0,0,0));
    while(1)
    {
        string op;
        objFile>>op;
        
        if (op == "v")
        {
            double x,y,z;
            objFile>>x>>y>>z;
            v.push_back(Vector3(x,y,z));
        } else
            if (op == "vt")
            {
                double x,y,z;
                objFile>>x>>y;
                vt.push_back(Vector3(x,y,0));
            } else
                if (op == "vn")
                {
                    double x,y,z;
                    objFile>>x>>y>>z;
                    vn.push_back(Vector3(x,y,z));
                } else
                    if (op == "f")
                    {
                        for (int i=0;i<3;i++)
                        {
                            int x,y,z;
                            int yf=0,zf=0;
                            string s;
                            stringstream ss;
                            objFile>>s;
                            // cout<<s<<endl;
                            int pos = s.find('/');
                            string st = s;
                            st[pos] = 0;
                            ss<<st;
                            ss>>x;
                            s.erase(0,pos+1);
                            // cout<<s<<endl;
                            pos = s.find('/');
                            st = s;
                            st[pos] = 0;
                            if (pos!=0)
                            {
                                // cout<<"gety from "<<st<<endl;
                                stringstream ss;
                                ss<<st;
                                ss>>y;
                                yf = 1;
                            }
                            s.erase(0,pos+1);
                            // cout<<s<<endl;
                            if (s!="")
                            {
                                stringstream ss;
                                // cout<<"getz from "<<s<<endl;
                                ss<<s;
                                ss>>z;
                                // cout<<z<<endl;
                                zf = 1;    
                            }
                            // cout<<x<<","<<y<<","<<z<<endl;
                            if (zf)
                            {
                                rvn.push_back(vn[z].x);
                                rvn.push_back(vn[z].y);
                                rvn.push_back(vn[z].z);
                                vnFlag = true;
                            }
                            
                            if (yf) 
                            {
                                rvt.push_back(vt[y].x);
                                rvt.push_back(vt[y].y);
                                vtFlag = true;
                            }
                            rv.push_back(v[x].x);
                            rv.push_back(v[x].y);
                            rv.push_back(v[x].z);
                        }
                    }
        if (objFile.eof()) break;
    }
    this->rv = new GLfloat[rv.size()];
    for (int i=0;i<rv.size();i++)
    {
        this->rv[i] = rv[i];
        
    }
    
    if (vnFlag)
    {
        this->rvn = new GLfloat[rvn.size()];
        for (int i=0;i<rvn.size();i++)
        {
            this->rvn[i] = rvn[i];
        }
        
    }
    vsize = rv.size();
    if (vtFlag)
    {
        this->rvt = new GLfloat[rvt.size()];
        for (int i=0;i<rvt.size();i++)
        {
            this->rvt[i] = rvt[i];
        }
        
    }

    glTexCoordPointer(2, GL_FIXED_ONLY_ARB, 0, &rvt);

}
void ImportedObj::draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,rv);
    if (vnFlag)
    {
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT, 0,rvn);

    }
//    if (vtFlag)
//    {
//        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//        glTexCoordPointer(2, GL_FIXED_ONLY_ARB, 0, rvt);
//        
//    }
    //    glutSolidCube(1);
    glBegin(GL_TRIANGLES);
    for (int i=0;i<vsize/3;i++)
    {
//        if (i % 3 ==0 )
        
        glArrayElement(i);
//        glNormal3f(rvn[i*3], rvn[i*3+1], rvn[i*3+2]);
//        glVertex3f(rv[i*3],rv[i*3+1],rv[i*3+2]);
//        if (i% 3 ==2)
        
    }
     glEnd();
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}