//
// Created by jgros on 8/24/2022.
//

#include <random>
//#include <iostream>
#include <GL/freeglut.h>

using namespace std;

// set seed and initialize rng as global vars
static random_device g_planter;
static ranlux24 g_gen(g_planter());


int *random_color() {
    // random color array
    static int c[3];
    // value distribution
    uniform_int_distribution<int> dist(0,255);
    // get color array randomly generated
    for (int & i : c) {
        i = dist(g_gen);
    }

    return c;
}

void init()
{
    //select clearing (background) color
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,glutGet(GLUT_WINDOW_WIDTH),0,glutGet(GLUT_WINDOW_HEIGHT),-1,1);

}

void display()
{
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0f);
    glBegin(GL_POINTS);

    //cout << "GL has Begun";

    for (int i = 0; i < glutGet(GLUT_WINDOW_WIDTH); i++) {
        //cout << "got X pixel";
        for (int j = 0; j < glutGet(GLUT_WINDOW_HEIGHT); j++) {
            //cout <<"got Y pixel";
            int *color;
            color = random_color();

            // verification that colors generated are not just black
            //cout << color[0] << endl;
            //cout << color[1] << endl;
            //cout << color[2] << endl;

            //cout << "Got random color array";
            glColor3f(color[0]/255.0, color[1]/255.0, color[2]/255.0);

            //cout << "selected color";
            glVertex2f(i, j);



            //cout << "painted pixel";
        }
    }

    glEnd();

    // Don't wait start processing buffered OpenGL routines
    glFlush();
}


