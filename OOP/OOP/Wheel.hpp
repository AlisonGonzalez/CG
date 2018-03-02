//
//  Wheel.hpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#pragma once            //Compiler directive, si ya se tiene
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

class Wheel
{
public:
    Wheel(float _x, float _y, float _z, float _r, float _g, float _b);            //Constructur
    ~Wheel();            //Deconstructor or destroyer
    
    void draw();        //Like display
    void update();        //Like idle
    
    //Qeui tambien se pueden declarar variables y atributos para los objetos
    // Declare != give value
    float x;            //position
    float y;            //position
    float z;            //position
    
    float r, g, b, rotX;        //color
};
