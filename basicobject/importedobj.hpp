//
//  importedobj.hpp
//  mygraphics
//
//  Created by zyhc on 1/9/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef importedobj_hpp
#define importedobj_hpp

#include <stdio.h>
#include <string>
#include "../object.hpp"
class ImportedObj:public Object{
public:
    GLfloat *rv,*rvt,*rvn;
    int vsize;
    bool vnFlag,vtFlag;
    ImportedObj(std::string);
    virtual void draw();
};
#endif /* importedobj_hpp */
