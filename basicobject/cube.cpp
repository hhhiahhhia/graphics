//
//  cube.cpp
//  mygraphics
//
//  Created by zyhc on 1/4/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#include "cube.hpp"
#include <sstream>
void Cube::draw()
{
    GLfloat size = 1;
    GLenum type = GL_QUADS;
    static GLfloat n[6][3] =
    {
        {-1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, -1.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 0.0, -1.0}
    };
    static GLint faces[6][4] =
    {
        {0, 1, 2, 3},
        {3, 2, 6, 7},
        {7, 6, 5, 4},
        {4, 5, 1, 0},
        {5, 6, 2, 1},
        {7, 4, 0, 3}
    };
    GLfloat v[8][3];
    GLint i;
    
    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
    
    for (i = 5; i >= 0; i--) {
        glBegin(type);
        glNormal3fv(&n[i][0]);
        glTexCoord2f( 0.0, 0.0 );
        glVertex3fv(&v[faces[i][0]][0]);
        glTexCoord2f( 1.0, 0.0 );
        glVertex3fv(&v[faces[i][1]][0]);
        glTexCoord2f( 1.0, 1.0 );
        glVertex3fv(&v[faces[i][2]][0]);
        glTexCoord2f( 0.0, 1.0 );
        glVertex3fv(&v[faces[i][3]][0]);
        glEnd();
    }
}
//std::string Cube::exportOBJ()
//{
//    using namespace std;
//    string ret;
//    stringstream ss;
//    GLfloat size = 1;
//    GLenum type = GL_QUADS;
//    static GLfloat n[6][3] =
//    {
//        {-1.0, 0.0, 0.0},
//        {0.0, 1.0, 0.0},
//        {1.0, 0.0, 0.0},
//        {0.0, -1.0, 0.0},
//        {0.0, 0.0, 1.0},
//        {0.0, 0.0, -1.0}
//    };
//    static GLint faces[6][4] =
//    {
//        {0, 1, 2, 3},
//        {3, 2, 6, 7},
//        {7, 6, 5, 4},
//        {4, 5, 1, 0},
//        {5, 6, 2, 1},
//        {7, 4, 0, 3}
//    };
//    GLfloat v[8][3];
//    GLint i;
//    
//    v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
//    v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
//    v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
//    v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
//    v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
//    v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
//    for (int i = 0;i<8;i++)
//    {
//        
//        ss<<"v "<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
//    }
//    for (int i = 0;i<8;i++)
//    {
//        ss<<"vt "<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
//    }
//    for (int i = 0;i<6;i++)
//    {
//        ss<<"vn "<<n[i][0]<<" "<<n[i][1]<<" "<<n[i][2]<<endl;
//    }
//    for (i = 5; i >= 0; i--) {
//        ss<<"f "<<faces[i][0]<<"/"<<faces[i][0]<<"/"<<i<<endl;
//        ss<<"f "<<faces[i][1]<<"/"<<faces[i][1]<<"/"<<i<<endl;
//        ss<<"f "<<faces[i][2]<<"/"<<faces[i][2]<<"/"<<i<<endl;
//        ss<<"f "<<faces[i][3]<<"/"<<faces[i][3]<<"/"<<i<<endl;
//    }
//    ss>>ret;
//    return ret;
//}