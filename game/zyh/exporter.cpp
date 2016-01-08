//
//  exporter.cpp
//  mygraphics
//
//  Created by zyhc on 1/8/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#include "exporter.hpp"
#include <string>
#include <fstream>
#include <sstream>
int Exporter::objNum = 0;

void grab(GLint width, GLint height)
{
    char head[54]={
        0x42, //0
        0x4d, //1
        0x66, //2
        0x75, //3
        0x00, //4
        0x00, //5
        0x00, //6
        0x00, //7
        0x00, //8
        0x00, //9
        0x36, //a
        0x00, //b
        0x00, //c
        0x00, //d
        0x28, //e
        0x00,//f
        0x00, //0
        0x00, //1
        0x64, //2
        0x00, //3
        0x00, //4
        0x00, //5
        0x64, //6
        0x00, //7
        0x00, //8
        0x00, //9
        0x01, //a
        0x00, //b
        0x18, //c
        0x00, //d
        0x00, //e
        0x00,//f
        0x00, //0
        0x00, //1
        0x30, //2
        0x75//3
    };
    GLint pixelLength;
    GLubyte * pixelDate;
    FILE * wfile;
    wfile = fopen( "grab2.bmp", "wb" );
    fwrite( head, 54, 1, wfile );
    fseek( wfile, 0x0012, SEEK_SET );
    fwrite( &width, sizeof(width), 1, wfile );
    fwrite( &height, sizeof(height ), 1, wfile );
    pixelLength = width * 3;
    if ( pixelLength % 4 != 0 )
    {
        pixelLength += 4 - pixelLength%4;
    }
    pixelLength *= height;
    pixelDate = (GLubyte *)malloc( pixelLength );
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glReadPixels( 0, 0, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixelDate );
    fseek( wfile, 0, SEEK_END );
    fwrite( pixelDate, pixelLength, 1, wfile );
    fclose( wfile );
    free( pixelDate );
}
void Exporter::script()
{
    if (keyPushed('O'))
    {
        for (int i=0;i<clickedList.size();i++)
        {
//            Object* obj =clickedList[i];
//            std::string s = findOBJString(obj);
//            std::stringstream ss;
//            ss<<"o"<<objNum<<".obj";
//            std::string fileName;
//            ss>>fileName;
//            std::fstream fs(fileName);
//            fs<<s;
//            objNum++;
        }
        int dx = glutGet( GLUT_WINDOW_WIDTH );
        
        int dy = glutGet( GLUT_WINDOW_HEIGHT );
        grab(dx,dy);
    }
}