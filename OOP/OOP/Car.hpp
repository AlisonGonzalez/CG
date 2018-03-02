//
//  Car.hpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#pragma once
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

#include "Wheel.hpp"

class Car
{
public:
    Car(float _r, float _g, float _b);
    ~Car();
    
    void draw();
    void update();
    
    float r, g, b;
    
    Wheel* wheels[4];
};


