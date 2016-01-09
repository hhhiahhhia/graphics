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
class LampButton: public ImportedObj {
public:
    LampButton():ImportedObj("lampButton.obj"){}
};
class Lamp:public ImportedObj {
public:
    LampButton* button;
    void addButton(LampButton* button){
        this->button = button;
        addChild(button);
    }
    Lamp():ImportedObj("lamp.obj")
    {
//        this->Button = Button;
//        addChild(Button);
        useTexture = true;
        //        texture = LoadTexture("metal2.bmp", 450 , 301);
        texture = LoadTexture("metal.bmp", 1024 , 646);
        color = Vector3(0.8,0.8,0.8);
    }
    Lamp(LampButton* Button):ImportedObj("lamp.obj")
    {
        this->button = Button;
        addChild(button);
        useTexture = true;
//        texture = LoadTexture("metal2.bmp", 450 , 301);
        texture = LoadTexture("metal.bmp", 1024 , 646);
        color = Vector3(0.8,0.8,0.8);
    }
};
#endif /* lamp_hpp */
