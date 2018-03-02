//
//  part.hpp
//  Roboto
//
//  Created by Alison González on 08/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#pragma once //Compiler directive //if you did it before, dont do it again
#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>

#ifndef ROBOTPARTS
#define ROBOTPARTS 18
#endif

class Part{
public:
    Part(float _r, float _g, float _b);
    ~Part();
    
    void draw();
    void update();
    
    float r,g,b;
};
