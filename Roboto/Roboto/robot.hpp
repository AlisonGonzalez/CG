//
//  robot.hpp
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

#include "part.hpp"
#ifndef ROBOTPARTS
#define ROBOTPARTS 18
#endif

enum RobotPart{
    BODY,
    NECK,
    HEAD,
    HIP,
    LSHOULDER,
    LFOREARM,
    LARM,
    LHAND,
    LTHIGH,
    LLEG,
    LFOOT,
    RSHOULDER,
    RFOREARM,
    RARM,
    RHAND,
    RTHIGH,
    RLEG,
    RFOOT
};

class Robot{
public:
    Robot();
    ~Robot();
    
    void draw();
    void update();
    
    float rotX[ROBOTPARTS];
    float rotYbody;
    //float rotY[ROBOTPARTS];
    //float rotZ[ROBOTPARTS];
    
    Part* parts[ROBOTPARTS];
};

