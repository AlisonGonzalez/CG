//
//  part.cpp
//  Roboto
//
//  Created by Alison González on 08/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#include "part.hpp"

Part::Part(float _r, float _g, float _b){
    r = _r;
    g = _g;
    b = _b;
}

Part::~Part(){
    
}

void Part::draw(){
    glPushMatrix();{
        glColor3f(r,g,b);
        glutSolidCube(1);
    }glPopMatrix();
}

void Part::update(){
}
