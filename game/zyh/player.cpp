//
//  player.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright 漏 2015 zyhc. All rights reserved.
//

#include "player.hpp"

extern float fDistance;

void Player::script()
{
    if (keyPushed('a'))
    {
		if ((camera->location.x-fDistance)>1.0)
		{
		  camera->location.x-=fDistance;
		  camera->center.x-=fDistance;
		}
    }
    if (keyPushed('d'))
    {
		if ((camera->location.x+fDistance)<99.0)
		{
		  camera->location.x+=fDistance;
		  camera->center.x+=fDistance;
		}
    }
	if (keyPushed('w'))
	{
		if ((camera->location.z-fDistance)>-99.0)
		{
		  camera->location.z-=fDistance;
		  camera->center.z-=fDistance;
		}
	}
	if (keyPushed('s'))
	{
		if ((camera->location.z+fDistance)<-1.0)
		{
		  camera->location.z+=fDistance;
		  camera->center.z+=fDistance;
		}
	}
	if (keyPushed('z'))
	{
		if ((camera->location.y+fDistance)<99.0)
		{
		  camera->location.y+=fDistance;
		  camera->center.y+=fDistance;
		}
	}
	if (keyPushed('c'))
	{
		if ((camera->location.y-fDistance)>1.0)
		{
		  camera->location.y-=fDistance;
		  camera->center.y-=fDistance;
		}
	}
}
