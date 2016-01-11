//
//  doorkey.hpp
//  mygraphics
//
//  Created by zyhc on 1/11/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef doorkey_hpp
#define doorkey_hpp

#include <stdio.h>
#include "../../basicobject/importedobj.hpp"
#include "../zyh/player.hpp"

class DoorKey: public ImportedObj
{
public:
    Player *mainPlayer;
    DoorKey():ImportedObj("key.obj")
    {
        useTexture  = true;
        texture = LoadTexture("wall.bmp", 0, 0);
        color = Vector3(.8,.5,.5);
       
    };
    virtual void clicked()
    {
        
        mainPlayer->hasKey = true;
        visible = false;
    }
};

#endif /* doorkey_hpp */
