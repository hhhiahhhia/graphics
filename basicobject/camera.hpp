//
//  camera.hpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include <stdio.h>
#include "../object.hpp"
class Camera : public Object
{
public:
    Vector3 center;
    Camera()
    {
        isCamera = true;
        location = Vector3(50.0,10.0,-1.0);
        center =Vector3(50.0,10.0,-10.0);
    }
};

#endif /* camera_hpp */
