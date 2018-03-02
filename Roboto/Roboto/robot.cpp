//
//  robot.cpp
//  Roboto
//
//  Created by Alison González on 08/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#include "robot.hpp"

Robot::Robot(){
    for(int i = 0; i < ROBOTPARTS; i++){
        parts[i] = new Part(1,1,1);
        rotX[i] = 0.0f;
    }
    parts[HEAD]->r = 0;
    parts[HEAD]->g = 0;
    parts[HEAD]->b = 1;
    parts[BODY]->r = 1;
    parts[BODY]->g = 0;
    parts[BODY]->b = 0;
    parts[LSHOULDER]->r = 1;
    parts[LSHOULDER]->g = 0;
    parts[LSHOULDER]->b = 0;
    parts[RSHOULDER]->r = 1;
    parts[RSHOULDER]->g = 0;
    parts[RSHOULDER]->b = 0;
    parts[LARM]->r = 1;
    parts[LARM]->g = 0;
    parts[LARM]->b = 0;
    parts[RARM]->r = 1;
    parts[RARM]->g = 0;
    parts[RARM]->b = 0;
    parts[LHAND]->r = 0;
    parts[LHAND]->g = 0;
    parts[LHAND]->b = 1;
    parts[RHAND]->r = 0;
    parts[RHAND]->g = 0;
    parts[RHAND]->b = 1;
    parts[HIP]->r = 0.5;
    parts[HIP]->g = 0.5;
    parts[HIP]->b = 0.5;
    parts[LLEG]->r = 0;
    parts[LLEG]->g = 0;
    parts[LLEG]->b = 1;
    parts[RLEG]->r = 0;
    parts[RLEG]->g = 0;
    parts[RLEG]->b = 1;
    parts[LFOOT]->r = 0;
    parts[LFOOT]->g = 0;
    parts[LFOOT]->b = 1;
    parts[RFOOT]->r = 0;
    parts[RFOOT]->g = 0;
    parts[RFOOT]->b = 1;
}

Robot::~Robot(){
}

void Robot::draw(){
    glPushMatrix();{
        parts[BODY]->draw();
        glPushMatrix();{
            //glRotatef(rotYbody,0,1,0);
            glTranslatef(0,0.6,0);
            glPushMatrix();{
                glScalef(0.3,0.1,0.3);
                parts[NECK]->draw();
            }glPopMatrix();
            
            glTranslatef(0,0.3,0);
            glScalef(0.5f,0.5f,0.5f);
            parts[HEAD]->draw();
        }glPopMatrix();
        
        //LEFT ARM
        glPushMatrix();{
            glTranslatef(0.7,0.3,0);
            glScalef(0.3,0.3,0.5);
            parts[LSHOULDER]->draw();
            glPushMatrix();{
                glTranslatef(0.0,-1.1,0);
                glScalef(0.7,1.1,1);
                parts[LFOREARM]->draw();
                glPushMatrix();{
                    glTranslatef(0.0,-1.2,0);
                    glScalef(1.1,1.3,1);
                    parts[LARM]->draw();
                    glPushMatrix();{
                        glTranslatef(0.0,-0.7,0);
                        glScalef(0.8,0.4,1);
                        parts[LHAND]->draw();
                    }glPopMatrix();
                }glPopMatrix();
            }glPopMatrix();
        }glPopMatrix();
        
        //RIGHT ARM
        
        glPushMatrix();{
            glTranslatef(-0.7,0.3,0);
            glScalef(0.3,0.3,0.3);
            parts[RSHOULDER]->draw();
            glPushMatrix();{
                glTranslatef(0.0,-1.1,0);
                glScalef(0.7,1.1,1);
                parts[RFOREARM]->draw();
                glPushMatrix();{
                    glTranslatef(0.0,-1.2,0);
                    glScalef(1.1,1.3,1);
                    parts[RARM]->draw();
                    glPushMatrix();{
                        glTranslatef(0.0,-0.7,0);
                        glScalef(0.8,0.4,1);
                        parts[RHAND]->draw();
                    }glPopMatrix();
                }glPopMatrix();
            }glPopMatrix();
        }glPopMatrix();
        
        //Parte Baja
        glPushMatrix();{
            glTranslatef(0.0,-0.6,0);
            glScalef(1,0.2,1);
            parts[HIP]->draw();
            
            //Pierna izquierda
            glPushMatrix();{
                glTranslatef(0.3,-2,0);
                glScalef(0.4,2.5,0.3);
                parts[LTHIGH]->draw();
                glPushMatrix();{
                    glTranslatef(0,-1.2,0);
                    glScalef(1.1,1.4,1);
                    parts[LLEG]->draw();
                    glPushMatrix();{
                        glTranslatef(0,-0.7,0.5);
                        glScalef(1,0.5,2);
                        parts[LFOOT]->draw();
                    }glPopMatrix();
                }glPopMatrix();
            }glPopMatrix();
            
            
            //Pierna derecha
            glPushMatrix();{
                glTranslatef(-0.3,-2,0);
                glScalef(0.4,2.5,0.3);
                parts[RTHIGH]->draw();
                glPushMatrix();{
                    glTranslatef(0,-1.2,0);
                    glScalef(1.1,1.4,1);
                    parts[RLEG]->draw();
                    glPushMatrix();{
                        glTranslatef(0,-0.7,0.5);
                        glScalef(1,0.5,2);
                        parts[RFOOT]->draw();
                    }glPopMatrix();
                }glPopMatrix();
            }glPopMatrix();
            
        }glPopMatrix();
    }glPopMatrix();
}

void Robot::update(){
    
}
