//
//  main.cpp
//  Roboto
//
//  Created by Alison González on 08/02/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

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

#include "robot.hpp"

Robot* robot; //pointer named "robot" to an object type robot

//w points to an object of type Wheel
//The * is for locate the object in memory. Is a pointer. Is a reference


void init() // FOR GLUT LOOP
{
    robot = new Robot(); //Instance, calls the constructor
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.3, 0.3, 0.3, 1.0);    // Clear the color state. Cambiar el color sw fondo
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers. Borramos todo de los bufers
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glPointSize(5);
    glLineWidth(2);
    
    glBegin(GL_LINES);
    
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    
    glEnd();
    
    robot->draw();
    
    
    glutSwapBuffers();                                                // Swap the hidden and visible buffers. Ultima linea de display
}

void idle()                                                            // Called when drawing is finished.
{
    robot->update();
    glutPostRedisplay();                                            // Display again. Ultima linea de idle
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glLoadIdentity();                                                // Reset the 3D matrix.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(5.0, 5.0, 5.0,                                        // Where the camera is. Posicion de la camara
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    display();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters. Iniciamos el GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}

