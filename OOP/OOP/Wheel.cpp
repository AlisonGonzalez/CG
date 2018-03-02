//
//  Wheel.cpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#include "Wheel.hpp"

Wheel::Wheel(float _x, float _y, float _z, float _r, float _g, float _b)            //"::" significan belongs to.
{
    x = _x;
    y = _y;
    z = _z;
    r = _r;
    g = _g;
    b = _b;
    rotX = 0;
}


Wheel::~Wheel()
{
}

void Wheel::draw()
{
    glPushMatrix();
    {
        glTranslatef(x, y, z);
        glRotatef(rotX, 1, 0, 0);
        glColor3f(r, g, b);
        //glutWireSphere(1, 20, 20);
        glScalef(0.2f, 0.5f, 0.5f);
        glutWireSphere(1, 20, 20);
    }
    glPopMatrix();
}

void Wheel::update()
{
    //Right place to increase rotation
    rotX += 0.01f;
}
