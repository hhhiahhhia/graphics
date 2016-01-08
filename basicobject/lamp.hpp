//
//  lamp.hpp
//  mygraphics
//
//  Created by zyhc on 1/9/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef lamp_hpp
#define lamp_hpp

#include <stdio.h>
#include "importedobj.hpp"
class lamp:public ImportedObj {
public:
    lamp():ImportedObj("lamp-old.obj"){}
};
#endif /* lamp_hpp */
