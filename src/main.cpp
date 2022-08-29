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
    //Initialise GLUT with command-line parameters.
    glutInit(&argc, argv);

    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Set the window size
    glutInitWindowSize(250,250);

    //Set the window position
    glutInitWindowPosition(100,100);

    //Create the window
    glutCreateWindow("A Simple OpenGL Windows Application with GLUT");

    //Call init (initialise GLUT
    init();

    //Call "display" function
    glutDisplayFunc(display);

    //Enter the GLUT event loop
    glutMainLoop();

    return 0;
}