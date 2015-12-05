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
#include "../../basicobject/camera.hpp"
class Player:public Object
{
public:
    double PI;
    double tVerticalAng, tHorizonAng, tRadius, tAngInc;
    double preMouseX = 0,preMouseY = 0;
    Camera* camera;
    virtual void script();
    Player();
};
#endif /* player_hpp */
