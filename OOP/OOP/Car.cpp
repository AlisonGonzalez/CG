//
//  Car.cpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#include "Car.hpp"

Car::Car(float _r, float _g, float _b)
{
    r = _r;
    g = _g;
    b = _b;
    
    for (int i = 0; i < 4; i++)
    {
        wheels[i] = new Wheel(1, 0, 1, 1, 1, 0);
    }
    wheels[0]->x = -1;
    wheels[1]->x = -1;
    wheels[0]->z = -1;
    wheels[3]->z = -1;
}


Car::~Car()
{
}

void Car::draw() {
    glPushMatrix();
    {
        glColor3f(r, g, b);
        glutSolidCube(1);
        for (int i = 0; i < 4; i++)
        {
            wheels[i]->draw();
        }
    }
    glPopMatrix();
}

void Car::update() {
    for (int i = 0; i < 4; i++)
    {
        wheels[i]->update();
    }
}
