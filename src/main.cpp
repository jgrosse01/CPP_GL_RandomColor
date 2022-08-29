/**
 * Jake Grosse
 * CS485: Computer Graphics
 * 29 August 2022
 *
 * We're going to make random color noise on a GL window! WOOHOO!
 */

#include <GL/freeglut.h>
#include "../include/local/GLUTwindowbuilder.h"

int main(int argc, char** argv)
{
    // the demo did it this way and i don't know what to pass in so default args we go!
    glutInit(&argc, argv);

    // single display in RGB color
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set the window size
    glutInitWindowSize(300,300);

    // Set the window position on screen
    glutInitWindowPosition(250,250);

    // Create the window
    glutCreateWindow("Random Color Noise!");

    // init method in GLUTwindowbuilder.cpp
    init();

    // sets the display function to use
    glutDisplayFunc(display);

    // window loop, basically just magic :)
    glutMainLoop();

    return 0;
}