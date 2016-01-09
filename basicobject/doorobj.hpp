//
//  doorobj.hpp
//  mygraphics
//
//  Created by zyhc on 1/10/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef doorobj_hpp
#define doorobj_hpp

#include <stdio.h>
#include "Importedobj.hpp"
class DoorObj : public ImportedObj
{
public:
    DoorObj():ImportedObj("door.obj"){}
};
#endif /* doorobj_hpp */
