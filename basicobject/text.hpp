//
//  text.hpp
//  mygraphics
//
//  Created by zyhc on 1/9/16.
//  Copyright © 2016 zyhc. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#include <stdio.h>
#include <string>
#include "canvas.hpp"
using namespace std;
class Text:public Canvas
{
public:
    string text;
    Text(string text):text(text){};
    virtual void draw();
};

#endif /* text_hpp */
