// Alison Ricardo González Cortés - A01064754
//
//  main.cpp
//  Arkanoid
//
//  Created by Alison González on 19/01/18.
//  Copyright © 2018 Alison González. All rights reserved.
//

#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include "freeglut.h"
#endif
#include <stdio.h>
#include <math.h>

#define HEIGHT 5
#define WIDTH 6

//Checks lives and score status
void checkStatus();

//Prints number of lives and player score
void printStatus();

//Bricks and player dimensions
float cellWidth = 0.5f;
float cellHeight = 0.1f;

//Adjustment for symmetric brick wall
float offsetX = -0.5f * cellWidth * WIDTH;
float offsetY = 1.0f;

//Player initial position and velocity
float playerX = 0.0f;
float playerY = -1.0f;
float playerVelocity = 0.1f;

//Ball initial position and velocity
float ballX = 0.0f;
float ballY = -0.2f;
float velocityX = 0.008;
float velocityY = 0.007;

//Saved ball velocities for pause/resume game logic
float savedVelocityX, savedVelocityY;

//Initial score, lives and paused status
int score = 0;
int lives = 3;
bool pausedGame = false;

//Brick wall
int wall[HEIGHT][WIDTH];
float colorsR[HEIGHT][WIDTH];
float colorsG[HEIGHT][WIDTH];
float colorsB[HEIGHT][WIDTH];

void init(){ // FOR GLUT LOOP
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            wall[row][col] = 1;
            colorsR[row][col] = (float)rand() / RAND_MAX;
            colorsG[row][col] = (float)rand() / RAND_MAX;
            colorsB[row][col] = (float)rand() / RAND_MAX;
        }
    }
    
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
    //Initial game status
    printStatus();
}

void drawSquare(float x, float y, float w, float h, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);{
        glColor3f(r, g, b);
        glVertex3f(x, y, 0);
        glVertex3f(x + w, y, 0);
        glVertex3f(x + w, y + h, 0);
        glVertex3f(x, y + h, 0);
    }
    glEnd();
}

void checkStatus(){
    //Checks if the player has used all their lives
    if(lives <= 0){
        velocityX = 0.0;
        velocityY = 0.0;
        playerVelocity = 0.0;
        printf("You lost!\n");
    }
    //Checks if the player has destroyed all bricks
    else if (score >= 300){
        velocityX = 0.0;
        velocityY = 0.0;
        playerVelocity = 0.0;
        printf("You Won!\n");
    }
    //Prints current game status
    else{
        printStatus();
    }
}

//Prints number of lives and total score
void printStatus(){
    printf("Lives: %d Score: %d\n", lives, score);
}

//Pause game logic
void pauseGame(){
    //If the game is paused, saves the ball's current X and Y velocities for later resume, marks the game as paused and prints the current status
    if(!pausedGame){
        pausedGame = true;
        savedVelocityX = velocityX;
        velocityX = 0.0;
        savedVelocityY = velocityY;
        velocityY = 0.0;
        printf("Game Paused\n");
    }
    //If the game is resumed, marks it, restores the ball's velocities and prints the status
    else{
        pausedGame = false;
        velocityX = savedVelocityX;
        velocityY = savedVelocityY;
        printf("Game Resumed\n");
    }
}

//Resets the ball's velocities and initial starting point and the player's inital starting point
void resetBallAndPlayer(){
    ballX = 0.0f;
    ballY = -0.2f;
    velocityX = abs(velocityX);
    velocityY = abs(velocityY);
    playerX = 0.0f;
    playerY = -1.0f;
}

//Moves the ball accordingly to its X and Y velocities
void moveBall(){
    ballX += velocityX;
    ballY += velocityY;
}

//Inverts the ball's velocities in X and Y-axis
void invertVelocity(int d){
    //X-axis
    if (d == 0) {
        velocityX = -velocityX;
    }
    //Y-axis
    else{
        velocityY = -velocityY;
    }
}

void checkCollision(){
    //Right and left walls
    if (ballX >= 1.7 || ballX <= -1.7){
        invertVelocity(0);
    }
    //Upper wall
    if (ballY >= 1.7) {
        invertVelocity(1);
    }
    //Lower wall
    if (ballY <= - 1.7) {
        resetBallAndPlayer();
        lives--;
        checkStatus();
    }
    //Player bar
    //Ball's actual radious (r = 1.0) doesn't work for some reason. A smaller number seems ok
    float radius = 0.04;
    if ((ballX + radius >= playerX && ballX - radius <= (playerX + cellWidth) && (ballY - radius) <= (playerY + cellHeight))){
        //If the ball hits the player by the top, it inverts its Y-velocity ...
        if(ballX + radius < playerX + cellWidth - 0.01 && ballX - radius > playerX + 0.01){
            invertVelocity(1);
        }
        //... otherwise, it inverts its X-velocity
        else{
            invertVelocity(0);
        }
    }
    //Bricks
    for (int i = 0; i < HEIGHT; i ++) {
        for (int j = 0; j < WIDTH; j++) {
            //(X, Y) for each brick
            float wallY = offsetY + i * cellHeight;
            float wallX = offsetX + j * cellWidth;
            //If the ball hits a non-empty brick...
            if(ballY - radius <= wallY + cellHeight && ballY + radius >= wallY && ballX + radius >= wallX && ballX - radius <= wallX + cellWidth && wall[i][j] == 1){
                //... by the top or bottom, it inverts its Y-velocity
                if(ballX - radius < wallX + cellWidth - 0.01 && ballX + radius > wallX + 0.01){
                    invertVelocity(1);
                }
                //... otherwise, it inverts its X-velocity
                else{
                    invertVelocity(0);
                }
                //Marks the brick as hit
                wall[i][j] = 0;
                //Adds 10 points to the total score
                score += 10;
                //Checks the game status
                checkStatus();
            }
        }
    }
    //Moves the ball
    moveBall();
}

//Draws the ball according to ballX and ballY
void drawCircle(float radius, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float radian = i * (3.1415f / 180.0f);
        float xcos = cos(radian) * radius;
        float ysin = sin(radian) * radius;
        glVertex3f(ballX + xcos, ballY + ysin, 0);
   
    }
    glEnd();
    //Checks if the ball is hitting something
    checkCollision();
}

void display(){                            // Called for each frame (about 60 times per second).
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
    
    //Loop for drawing bricks
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (wall[row][col] == 1) {
                drawSquare(offsetX + col * cellWidth, offsetY + row * cellHeight, cellWidth, cellHeight, colorsR[row][col], colorsG[row][col], colorsB[row][col]);
            }
        }
    }
    //Draws the player
    drawSquare(playerX, playerY, cellWidth, cellHeight, 0.5f, 0.5f, 0.5f);
    //Draws the ball
    drawCircle(0.05, 1, 1, 1);
    
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
    gluLookAt(0.0, 0.0, 5.0,                                        // Where the camera is.
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    display();
}

//Cheks if 'P' is pressed to pause the game
void processKeys(unsigned char key, int x, int y){
    if (key == 'p') {
        pauseGame();
    }
}

//Checks player's movement
void arrows(int k, int x, int y){
    switch (k) {
        case GLUT_KEY_LEFT:
            if (!pausedGame && playerX > -1.8) {
                playerX -= playerVelocity;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (!pausedGame && playerX < 1.3) {
                playerX += playerVelocity;
            }
            break;
    }
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutKeyboardFunc(processKeys);
    glutSpecialFunc(arrows);
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
