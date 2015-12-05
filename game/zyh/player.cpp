//
//  player.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 漏 2015 zyhc. All rights reserved.
//

#include "player.hpp"


void Player::script()
{
    double fDistance = 0.1;
    if (keyPushed('a'))
    {
        camera->location.x-=fDistance;
        camera->center.x-=fDistance;
    }
    if (keyPushed('d'))
    {
        camera->location.x+=fDistance;
        camera->center.x+=fDistance;
    }
	if (keyPushed('w'))
	{
        camera->location.z-=fDistance;
        camera->center.z-=fDistance;
	}
	if (keyPushed('s'))
	{
        camera->location.z+=fDistance;
        camera->center.z+=fDistance;
	}
	if (keyPushed('z'))
	{
        camera->location.y+=fDistance;
        camera->center.y+=fDistance;
	}
	if (keyPushed('c'))
	{
        camera->location.y-=fDistance;
        camera->center.y-=fDistance;
	}
}
