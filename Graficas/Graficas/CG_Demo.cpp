/*
 * Sergio Ruiz.
 *
 * TC3022. Computer Graphics Course.
 * Basic template OpenGL project.
 */

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

int shape;

void init(){ // FOR GLUT LOOP
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.15, 0.15, 0.15, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
    shape = 1;
}

void display(){                            // Called for each frame (about 60 times per second).
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    
    //JAPAN
    if (shape == 1){
        //White background
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, 5, 0);
        glVertex3f(-7.5, 5, 0);
        glVertex3f(-7.5, -5, 0);
        glVertex3f(7.5, -5, 0);
        glEnd();
        //Red cirlce
        glColor3f(0.74, 0.0, 0.16);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float radian = i * (3.1415f / 180.0f);
            float xcos = cos(radian) * 2.75;
            float ysin = sin(radian) * 2.75;
            glVertex3f(xcos, ysin, 0.01);
        }
        glEnd();
    }
    
    //GERMANY
    if (shape == 2){
        //Black rectangle
        glColor3f(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, 4.5, 0);
        glVertex3f(-7.5, 4.5, 0);
        glVertex3f(-7.5, 1.5, 0);
        glVertex3f(7.5, 1.5, 0);
        glEnd();
        //Red rectangle
        glColor3f(0.87, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, 1.5, 0);
        glVertex3f(-7.5, 1.5, 0);
        glVertex3f(-7.5, -1.5, 0);
        glVertex3f(7.5, -1.5, 0);
        glEnd();
        //Yellow rectangle
        glColor3f(1, 0.81, 0);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, -1.5, 0);
        glVertex3f(-7.5, -1.5, 0);
        glVertex3f(-7.5, -4.5, 0);
        glVertex3f(7.5, -4.5, 0);
        glEnd();
    }
    
    //JAMAICA
    if (shape == 3){
        //Yellow background
        glColor3f(1, 0.82, 0);
        glBegin(GL_POLYGON);
        glVertex3f(10, 5, 0);
        glVertex3f(-10, 5, 0);
        glVertex3f(-10, -5, 0);
        glVertex3f(10, -5, 0);
        glEnd();
        //Green triangles
        glColor3f(0, 0.61, 0.21);
        glBegin(GL_TRIANGLES);
        //Top
        glVertex3f(9, 5, 0.10);
        glVertex3f(-9, 5, 0.01);
        glVertex3f(0, 0.5, 0.01);
        //Bottom
        glVertex3f(9, -5, 0.01);
        glVertex3f(-9, -5, 0.01);
        glVertex3f(0, -0.5, 0.01);
        //Black triangles
        glColor3f(0, 0, 0);
        glBegin(GL_TRIANGLES);
        //Right
        glVertex3f(10, 4.2, 0.01);
        glVertex3f(10, -4.2, 0.01);
        glVertex3f(1.5, 0, 0.01);
        //Left
        glVertex3f(-10, 4.2, 0.01);
        glVertex3f(-10, -4.2, 0.01);
        glVertex3f(-1.5, 0, 0.01);
        glEnd();
    }
    
    //FINLAND
    if (shape == 4){
        //White background
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        glVertex3f(8, 5, 0);
        glVertex3f(-8, 5, 0);
        glVertex3f(-8, -5, 0);
        glVertex3f(8, -5, 0);
        glEnd();
        //Blue stripes
        glColor3f(0, 0.2, 0.5);
        //Vertical
        glBegin(GL_POLYGON);
        glVertex3f(-0.6, 5, 0.01);
        glVertex3f(-3.3, 5, 0.01);
        glVertex3f(-3.3, -5, 0.01);
        glVertex3f(-0.6, -5, 0.01);
        glEnd();
        //Horizontal
        glBegin(GL_POLYGON);
        glVertex3f(-8, 1.3, 0.01);
        glVertex3f(-8, -1.3, 0.01);
        glVertex3f(8, -1.3, 0.01);
        glVertex3f(8, 1.3, 0.01);
        glEnd();
    }
    
    //BAHAMAS
    if (shape == 5){
        //Cyan Background
        glColor3f(0, 0.47, 0.55);
        glBegin(GL_POLYGON);
        glVertex3f(10, 5, 0);
        glVertex3f(-10, 5, 0);
        glVertex3f(-10, -5, 0);
        glVertex3f(10, -5, 0);
        glEnd();
        //Yellow stripe
        glColor3f(1, 0.78, 0.17);
        glBegin(GL_POLYGON);
        glVertex3f(9.95, 1.67, 0.01);
        glVertex3f(-9.95, 1.67, 0.01);
        glVertex3f(-9.95, -1.67, 0.01);
        glVertex3f(9.95, -1.67, 0.01);
        glEnd();
        //Black triangle
        glColor3f(0, 0, 0);
        glBegin(GL_TRIANGLES);
        glVertex3f(-9.99, 4.95, 0.11);
        glVertex3f(-1.99, 0, 0.11);
        glVertex3f(-9.99, -4.95, 0.11);
        glEnd();
    }
    
    //SOMALIA
    if (shape == 6) {
        //Blue background
        glColor3f(0.25, 0.53, 0.86);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, 5, 0);
        glVertex3f(-7.5, 5, 0);
        glVertex3f(-7.5, -5, 0);
        glVertex3f(7.5, -5, 0);
        glEnd();
        //White star
        glColor3f(1, 1, 1);
        glBegin(GL_POLYGON);
        int counter = 1;
        for (int i = 54; i < 380 ; i += 36) {
            float radian = (i * 3.1415f) / 180.0f;
            //External vertex
            if (counter % 2 == 0) {
                float xcos = cos(radian) * 2;
                float ysin = sin(radian) * 2;
                glVertex3f(xcos, ysin, 0.01);
            //Internal vertex
            }else{
                float xcos = cos(radian) * 0.67;
                float ysin = sin(radian) * 0.67;
                glVertex3f(xcos, ysin, 0.01);
            }
            counter++;
        }
        /*glVertex3f(0.39, 0.61, 0.01);     //2
        glVertex3f(0, 2, 0.01);            //3
        glVertex3f(-0.39, 0.61, 0.01);     //4
        glVertex3f(-1.9, 0.61, 0.01);      //5
        glVertex3f(-0.64, -0.2, 0.01);     //6
        glVertex3f(-1.17, -1.61, 0.01);    //7
        glVertex3f(0, -0.67, 0.01);        //8
        glVertex3f(1.17, -1.61, 0.01);     //9
        glVertex3f(0.64, -0.2, 0.01);     //10
        glVertex3f(1.9, 0.61, 0.01);       //1
        */
        glEnd();
    }
    
    //GREECE
    if (shape == 7){
        //Blue background
        glColor3f(0.04, 0.36, 0.68);
        glBegin(GL_POLYGON);
        glVertex3f(7.5, 5, 0);
        glVertex3f(-7.5, 5, 0);
        glVertex3f(-7.5, -5, 0);
        glVertex3f(7.5, -5, 0);
        glEnd();
        //White stripes
        glColor3f(1, 1, 1);
        //Horizontal
        float counter = 3.9;
        for (int i = 0; i < 4; i++) {
            if(i > 1){
                glBegin(GL_POLYGON);
                glVertex3f(7.49, counter, 0.01);
                glVertex3f(7.49, counter - 1.1, 0.01);
                glVertex3f(-7.49, counter - 1.1, 0.01);
                glVertex3f(-7.49, counter, 0.01);
                glEnd();
            }else{
                glBegin(GL_POLYGON);
                glVertex3f(7.49, counter, 0.01);
                glVertex3f(7.49, counter - 1.1, 0.01);
                glVertex3f(-2, counter - 1.1, 0.01);
                glVertex3f(-2, counter, 0.01);
                glEnd();
            }
            counter = counter - 2.2;
        }
        glBegin(GL_POLYGON);
        glVertex3f(-2, 2.8, 0.01);
        glVertex3f(-2, 1.7, 0.01);
        glVertex3f(-7.45, 1.7, 0.01);
        glVertex3f(-7.45, 2.8, 0.01);
        glEnd();
        //Vertical
        glBegin(GL_POLYGON);
        glVertex3f(-5.29, 5, 0.01);
        glVertex3f(-4.19, 5, 0.01);
        glVertex3f(-4.19, -0.5, 0.01);
        glVertex3f(-5.29, -0.5, 0.01);
        glEnd();
    }
    
    glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle(){                                                            // Called when drawing is finished.
    glutPostRedisplay();                                            // Display again.
}

void reshape(int x, int y){                                            // Called when the window geometry changes.
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glLoadIdentity();                                                // Reset the 3D matrix.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 0.0, 35.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    display();
}

void keys(unsigned char k, int x, int y){
    switch(k){
        case '1':
            shape = 1;
            break;
        case '2':
            shape = 2;
            break;
        case '3':
            shape = 3;
            break;
        case '4':
            shape = 4;
            break;
        case '5':
            shape = 5;
            break;
        case '6':
            shape = 6;
            break;
        case '7':
            shape = 7;
            break;
        default:
            shape = 1;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutKeyboardFunc(keys);
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
