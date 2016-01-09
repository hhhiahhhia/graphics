//#include <fstream>
//#include <iostream>
//#include <string>
//#include <regex>
//#include <sstream>
//using namespace std;
//int main(int argc,char** argv)
//{
//    fstream objFile(argv[1]);
//    string className(argv[2]);
//    fstream out("basicobject/" + className+".cpp",ios::out);
//    fstream hout("basicobject/" + className + ".hpp",ios::out);
//    hout<<"#include \"../object.hpp\""<<endl;
//    hout<<"class "<<className<<": public Object {"<<endl;
//    hout<<"\t virtual void draw();"<<endl;
//    hout<<"};"<<endl;
//    hout.close();
//    cout<<className+".cpp"<<endl;
//    out<<"#include \""<<className<<".hpp\""<<endl;
//    out<<"void "<<className<<"::draw()"<<endl;
//    out<<"{"<<endl;
//    double v[1000][3],vt[1000][3],vn[1000][3];
//    int indexv = 1, indexvt = 1, indexvn = 1;
//    while(1)
//    {
//        string op;
//        objFile>>op;
//        if (op == "v")
//        {
//            cout<<"V!"<<endl;
//            objFile>>v[indexv][0]>>v[indexv][1]>>v[indexv][2];
//            indexv++;
//        } else
//        if (op == "vt")
//        {
//            cout<<"Vt"<<endl;
//            objFile>>vt[indexvt][0]>>vt[indexvt][1];
//            indexvt++;
//        } else
//        if (op == "vn")
//        {
//            cout<<"Vn"<<endl;
//            objFile>>vn[indexvn][0]>>vn[indexvn][1]>>vn[indexvn][2];
//            indexvn++;
//        } else
//        if (op == "f")
//        {
//            out<<"\tglBegin(GL_TRIANGLES);"<<endl;
//            for (int i=0;i<3;i++)
//            {
//                int x,y,z;
//                bool yf=0,zf=0;
//                string s;
//                stringstream ss;
//                objFile>>s;
//                cout<<s<<endl;
//                int pos = s.find('/');
//                if (pos== string::npos)
//                {
//                    ss<<s;
//                    ss>>x;
//                    out<<"glVector3f("<<v[x][0]<<","<<v[x][1]<<","<<v[x][2]<<");"<<endl;
//                }
//                string st = s;
//                st[pos] = 0;
//                ss<<st;
//                ss>>x;
//                s.erase(0,pos+1);
//                cout<<s<<endl;
//                pos = s.find('/');
//                st = s;
//                st[pos] = 0;
//                if (pos!=0)
//                {
//                    cout<<"gety from "<<st<<endl;
//                    stringstream ss;
//                    ss<<st;
//                    ss>>y;   
//                    yf = 1; 
//                } 
//                s.erase(0,pos+1);
//                cout<<s<<endl;
//                if (s!="")
//                {
//                    stringstream ss;
//                    cout<<"getz from "<<s<<endl;
//                    ss<<s;
//                    ss>>z;
//                    cout<<z<<endl;
//                    zf = 1;    
//                }
//                cout<<x<<","<<y<<","<<z<<endl;
//                if (zf)
//                    out<<"\tglNormal3f("<<vn[z][0]<<","<<vn[z][1]<<","<<vn[z][2]<<");"<<endl;
//                if (yf) 
//                    out<<"\tglTexCoord2f("<<vt[y][0]<<","<<vt[y][1]<<");"<<endl;
//                out<<"\tglVertex3f("<<v[x][0]<<","<<v[x][1]<<","<<v[x][2]<<");"<<endl;   
//            }
//            out<<"\tglEnd();"<<endl; 
//        }
//        if (objFile.eof()) break;
//    }
//    out<<"}"<<endl;
//    out.close();
//    return 0;
//    
//}