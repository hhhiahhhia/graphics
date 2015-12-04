//
//  player.hpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "camera.hpp"
class Player:public Object
{
public:
    Camera* camera;
    virtual void script();
};
#endif /* player_hpp */
