//
//  zyh.cpp
//  mygraphics
//
//  Created by zyhc on 12/1/15.
//  Copyright © 2015 zyhc. All rights reserved.
//

#include "zyh.hpp"
#include "../../basicobject/triangle.hpp"
#include "rotatingtriangle.hpp"
#include "player.hpp"
#include "../../basicobject/light.hpp"
#include "../../basicobject/cube.hpp"
#include "mainlight.hpp"
#include "exporter.hpp"
#include "../../basicobject/monkey.hpp"
#include "../../basicobject/lamp.hpp"
#include "../../basicobject/text.hpp"

Player *player;
MainLight *mainLight;
Text* mainText;
void zyhPart(std::vector<Object*>* objectList)
{
//    Triangle *t2 = new Triangle;
//    t2->location.x =50.0;
//    t2->location.y = 10;
//    t2->location.z = -50;
//    objectList->push_back(t2);
//    Triangle *t3 = new Triangle;
//    t3->location.x = -20;
//    t3->location.y = 0;
//    t3->location.z = 0;
//    t3->size = Vector3(5,5,5);
//    t2->addChild(t3);
//    RotatingTriangle* rt1 = new RotatingTriangle;
//    rt1->location = Vector3(70,10,-50);
//    objectList->push_back(rt1);
    player = new Player;
    player->camera = dynamic_cast<Camera*>((*objectList)[0]);
    objectList->push_back(player);
    
    MainLight *light = new MainLight(Vector3(0.5,0.5,0.5));
    light->location = Vector3(50,90,-50);
    light->ambient = Vector3(0.4,0.4,0.4);
    objectList->push_back(light);
    mainLight = light;
//    Cube * c1 = new Cube;
//    c1->location = Vector3(30,10,-30);
//    c1->useTexture = true;
//    c1->texture = LoadTexture("monet.bmp", 512, 512);
//    objectList->push_back(c1);
//    Exporter *exp = new Exporter;
//    objectList->push_back(exp);
    

//    Lamp *la = new Lamp(new LampButton);
//    la->location = Vector3(10,10,-30);
//    la->size = Vector3(0.15,0.15,0.15);
//    objectList->push_back(la);

    monkey *m = new monkey;
    m->location = Vector3(50,10,-10);
    m->size = Vector3(0.3,0.3,0.3);
    m->color = Vector3(0.5,0.5,0.5);
    objectList->push_back(m);
    
    Text *text = new Text("push 0 to close or open the light");
    text->location = Vector3(50,90,0);
    text->size = Vector3(.5,.5,.5);
    objectList->push_back(text);
    mainText = text;
    
    
}