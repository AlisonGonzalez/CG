/*
 TC3022. Computer Graphics
 Sergio Ruiz
 External geometry loader example.
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdio.h>
#include <math.h>
// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
#include "glm.hpp" /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#define DO_ROTATION_X

GLfloat        rotationY = 0.0f;
GLfloat        rotationX = 0.0f;

GLfloat*    mat0_specular;
GLfloat*    mat0_diffuse;
GLfloat*    mat0_shininess;
GLfloat*    light0_position;

GLMmodel*    model;

void init(void)
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    
    /*
     A C T I V I T Y. PROJECT TEAMS.
     ---------------
     
     1. Open a text file and type (or copy/paste) lines 47-67:
     
     # PYRAMID
     
     # VERTICES. Format:
     # v X Y Z
     
     v -1.0  0.0  1.0
     v  1.0  0.0  1.0
     v  1.0  0.0 -1.0
     v -1.0  0.0 -1.0
     
     # NORMALS. Format:
     # vn X Y Z
     
     vn  0  0  -1
     
     # FACES. Format:
     # f VERTEX_INDEX/TEXTURE_INDEX/NORMAL_INDEX
     # >>>Indices start from 1.
     
     f 1//1 2//1 3//1
     f 1//1 3//1 4//1
     
     2. Save the file as "assets/pyramid.obj" inside this project.
     3. This information is the base face only. Finish the pyramid of height SQRT(2)
     3.1 Do not repeat vertices, normals or faces.
     3.2 To make the process easier, complete the faces in the following order:
     FRONT, RIGHT, BACK, LEFT
     3.3 Write vertices forming each face starting from the bottom-left and counter-clockwise.
     Remember not to repeat the vertices you already have.
     4. When the pyramid is ready, create a new folder (OBJ_ACTIVITY) and copy your pyramid.obj and a screen capture
     of this application displaying your pyramid.
     5. Download mystery1.obj to your assets folder.
     5.1 Read the rest of this code and add a screen capture of this application displaying the full shape
     of mystery1.obj to your OBJ_ACTIVITY folder.
     6. Download mystery2.obj to your assets folder.
     6.1 Read the rest of this code and add a screen capture of this application displaying the full shape
     of mystery2.obj to your OBJ_ACTIVITY folder.
     7. Visit http://tf3dm.com/ or https://turbosquid.com and download an OBJ of a car. Display it and save a screenshot of this application
     to your OBJ_ACTIVITY folder.
     8. Upload OBJ_ACTIVITY.zip to Blackboard.
     */
    
    model = glmReadOBJ("mystery1.obj");
    // When the model is too big make it fit inside a 1x1x1 cube:
    glmUnitize(model);
    // You can also scale it later:
    glmScale(model, 2.0f);
    
    // When the model doesn't have normals, glm can add them:
    glmFacetNormals(model); // and then per face
    glmVertexNormals(model, 45.0f);
    
    
    light0_position = new GLfloat[4];
    light0_position[0] = 3;
    light0_position[1] = 3;
    light0_position[2] = 0;
    light0_position[3] = 1; // POINT LIGHT
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    
    mat0_specular = new GLfloat[4];
    mat0_specular[0] = 1.0f;
    mat0_specular[1] = 1.0f;
    mat0_specular[2] = 1.0f;
    mat0_specular[3] = 1.0f;
    
    mat0_diffuse = new GLfloat[4];
    mat0_diffuse[0] = 0.8f;
    mat0_diffuse[1] = 0.7f;
    mat0_diffuse[2] = 0.6f;
    mat0_diffuse[3] = 1.0f;
    
    mat0_shininess = new GLfloat[1];
    mat0_shininess[0] = 100.0f;
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
    
    glPushMatrix();
    {
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        glmDraw(model, GLM_SMOOTH);
    }
    glPopMatrix();
    glutSwapBuffers();
}

void idle (void)
{
    rotationY += 0.08f;
    if (rotationY > 360)
    {
        rotationY = 0;
    }
    
#ifdef DO_ROTATION_X
    rotationX += 0.02f;
    if (rotationX > 360)
    {
        rotationX = 0;
    }
#endif
    
    glutPostRedisplay ();
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.01, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 2.1, 5.3, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 50);
    glutCreateWindow ("OBJ Loader!");
    glutReshapeFunc (reshape);
    init ();
    glutDisplayFunc(display);
    glutIdleFunc (idle);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}

