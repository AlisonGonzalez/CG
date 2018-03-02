//
//  Robot.cpp
//  OOP
//
//  Created by Alison González on 06/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#include "Robot.hpp"

Robot::Robot()
{
    for (int i = 0; i < ROBOTPARTS; i++)
    {
        
    }
}


Robot::~Robot()
{
    glPushMatrix();
    {
        parts[BODY]->draw(); //cube, side 1
        glPushMatrix();
        {
            //glRotatef(rotY[NECK], 0, 1, 0);
            glTranslated(0, 0.05, 0);
            glPushMatrix();
            {
                glScalef(0.2, 0.1, 0.2);
                parts[NECK]->draw();
            }
            glPopMatrix();
            glTranslatef(0, 0.25, 0);
            glScalef(0.5f, 0.5f, 0.5f);
            parts[HEAD]->draw();
        }
    }
}

void Robot::draw()
{
    glPushMatrix();
    {
        parts[BODY]->draw(); //cube, side 1
        glTranslatef(0, 0.05, 0);
        glPushMatrix();
        {
            glScalef(0.2, 0.1, 0.2);
            parts[NECK]->draw();
        }
        glPopMatrix();
        glTranslatef(0, 0.25, 0);
        glScalef(0.5f, 0.5f, 0.5f);
        parts[HEAD]->draw();
    }
}

void Robot::update()
{
    //
}
