/*
 Alison Ricardo González Cortés - A01064754
 
 Results for RGB: (0.5180, 1.1693, 0.7377)
 Results for OpenGL: (0.7372, 0.9647, 0.6862)
 
 The RGB values show a higher-than-normal green value, but the final value of the light is accurate.
 The OpenGL values varie a little but they are very close to the calculated value.
 This difference might be due to significative numbers in the manual calculation,
 the correct placement of the color picker, but they are very close none the less.
 
 */

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

GLfloat*    mat0_ambient;
// ksr, ksg, ksb:
GLfloat*    mat0_specular; //<---------------------------------------Material 0 - specular
// kdr, kdg, kdb:
GLfloat*    mat0_diffuse; //<----------------------------------------Material 0 - diffuse
// alpha:
GLfloat*    mat0_shininess; //<--------------------------------------Material 0 - specular power
// Ir, Ig, Ib:
GLfloat*    light0_position; //<-------------------------------------Light 0    - location
//
//----------------------------------------------------------------------------------------------
//
void init( void )
{
    glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f ); //<---------------------Clear color
    glShadeModel ( GL_SMOOTH ); //<----------------------------------Smooth shading
    
    //->MATERIAL 0 BEGINS
    mat0_ambient        = new GLfloat[4]; //<------------------------Reserve memory
    mat0_ambient[0]    = 0.026f; //<----------------------------------S0r
    mat0_ambient[1]    = 0.026f; //<----------------------------------S0g
    mat0_ambient[2]    = 0.026f; //<----------------------------------S0b
    mat0_ambient[3]    = 1.0f; //<----------------------------------S0a
    
    
    
    mat0_specular        = new GLfloat[4]; //<------------------------Reserve memory
    mat0_specular[0]    = 0.042f; //<----------------------------------S0r
    mat0_specular[1]    = 1.0f; //<----------------------------------S0g
    mat0_specular[2]    = 1.0f; //<----------------------------------S0b
    mat0_specular[3]    = 1.0f; //<----------------------------------S0a
    
    mat0_diffuse        = new GLfloat[4]; //<------------------------Reserve memory
    mat0_diffuse[0]        = 1.0f; //<----------------------------------D0r
    mat0_diffuse[1]        = 0.572f; //<----------------------------------D0g
    mat0_diffuse[2]        = 0.064f; //<----------------------------------D0b
    mat0_diffuse[3]        = 1.0f; //<----------------------------------D0a
    
    //Alpha
    mat0_shininess        = new GLfloat[1]; //<------------------------Reserve memory
    mat0_shininess[0]    = 4.545f; //<---------------------------------Material 0 specular power
    //<-MATERIAL 0 ENDS
    
    //->LIGHT 0 BEGINS
    light0_position        = new GLfloat[4]; //<------------------------Reserve memory
    light0_position[0]    = -3.924f; //<----------------------------------L0x
    light0_position[1]    = 7.43f; //<----------------------------------L0y
    light0_position[2]    = -0.685f; //<----------------------------------L0z
    light0_position[3]    = 1.0f; //<----------------------------------L0w
    
    /*
     Important: light position is L0(lx,ly,lz,lw).
     -If lw = 0, configures a directional light, and parameters lx, ly y lz define its direction.
     -If lw = 1, configures a point light, and parameters lx, ly y lz define its location.
     */
    //<-LIGHT 0 ENDS
    
    // Locate LIGHT 0:
    glLightfv( GL_LIGHT0, GL_POSITION,  light0_position );
    // Enable lighting:
    glEnable( GL_LIGHTING );
    // Enable LIGHT 0:
    glEnable( GL_LIGHT0 );
    // Enable depth test (distinguish between near and far faces):
    glEnable( GL_DEPTH_TEST );
}
//
//----------------------------------------------------------------------------------------------
//
/*
 Callback triggered when display is required.
 */
void display( void )
{
    // Clear depth and color buffers:
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    // State machine: set active material:
    //glMaterialfv( GL_FRONT, GL_AMBIENT, mat0_ambient);
    glMaterialfv( GL_FRONT,     GL_DIFFUSE,   mat0_diffuse        );
    glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat0_specular    );
    glMaterialfv( GL_FRONT,  GL_SHININESS, mat0_shininess    );
    // Draw triangle:
        //Side size
        GLfloat hside = 0.5f;
        glBegin(GL_TRIANGLES);
        
        //A
        glNormal3f(-0.749, 0.4424, 0.4918);
        glVertex3f(-1.8270, 2.713, -1.735);
        //B
        glNormal3f(-0.749, 0.4424, 0.4918);
        glVertex3f(0.7898, 3.875, 1.209);
        //C
        glNormal3f(-0.749, 0.4424, 0.4918);
        glVertex3f(0.0180, 6.396, -2.235);
        
        glEnd();

    // Exchange visible and hidden buffers:
    glutSwapBuffers();
}
//
//----------------------------------------------------------------------------------------------
//
/*
 Callback triggered when drawing routines are done.
 */
void idle( void )
{
    glutPostRedisplay(); //<-----------------------------------------Draw again.
}
//
//----------------------------------------------------------------------------------------------
//
/*
 Callback triggered when window dimensions change.
 */
void reshape( int w, int h )
{
    // Update the viewport:
    glViewport( 0, 0, (GLsizei) w, (GLsizei) h );
    // Go to projection mode (2D):
    glMatrixMode( GL_PROJECTION );
    // Load identity matrix in the active matrix (GL_PROJECTION):
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.5, 50.0);
    // Go to model-view mode (3D):
    glMatrixMode( GL_MODELVIEW );
    // Load identity matrix in the active matrix (GL_MODELVIEW):
    glLoadIdentity();
    //Camera
    glViewport(0, 0, w, h);
    gluLookAt(-6.619, 5.096, 1.144,                                        // Where the camera is.
              //0.0, 0.0, 0.0,                                                // To where the camera points at.
              -0.33973, 4.328, -0.9203,
              0.0, 1.0, 0.0);                                                // "UP" vector.

}
//
//----------------------------------------------------------------------------------------------
//
/*
 Main function.
 Configure GLUT and execute GLUT MAIN LOOP.
 */
int main( int argc, char** argv )
{
    // Initialize GLUT:
    glutInit( &argc, argv );
    // Initialize the display mode using 2 buffers (visible and hidden),
    // 3 color channels and the depth buffer:
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    // Initialize window and size:
    glutInitWindowSize( 500, 500 );
    // Set window position:
    glutInitWindowPosition( 100, 100 );
    // Display the window and set its title to this program's name.
    glutCreateWindow( argv[0] );
    // Call 'init':
    init();
    // Register GLUT callbacks:
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutIdleFunc( idle );
    // Start rendering:
    glutMainLoop();
    // ANSI C requires an integer. 0: OK, other than 0: error number.
    return 0;
}
//
//----------------------------------------------------------------------------------------------

