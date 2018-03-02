//
//  Robot.hpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

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

#include "Part.hpp"

#ifndef ROBOTPARTS
#define ROBOTPARTS 18
#endif

class Robot
{
public:
    Robot();
    ~Robot();
    
    float rotX[ROBOTPARTS];
    float rotY[ROBOTPARTS];
    float rotZ[ROBOTPARTS];
    Part* parts[ROBOTPARTS];
};

enum RobotPart
{
    BODY, NECK, HEAD, HIP,
    LSHOULDER, LFOREARM, LARM, LHAND, LTIGH, LLEG, LFOOT,
    RSHOULDER, RFOREARM, RARM, RHAND, RTIGH, RLEG, RFOOT
};

