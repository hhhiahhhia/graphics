//
//  player.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "player.hpp"
void Player::script()
{
    if (keyPushed('a'))
    {
        camera->location.x--;
        camera->center.x--;
    }
    if (keyPushed('d'))
    {
        camera->location.x++;
        camera->center.x++;
    }
    if (keyPushed('s'))
    {
        camera->location.z++;
        camera->center.z++;
    }
    if (keyPushed('w'))
    {
        camera->location.z--;
        camera->center.z--;
    }
}