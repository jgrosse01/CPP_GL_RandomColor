//
// Created by jgros on 8/24/2022.
//

#include <random>
#include <GL/freeglut.h>

// set seed and initialize rng as global vars
static std::random_device g_planter;
static std::ranlux24 g_gen(g_planter());

// rgb array buffer to store random noise image
int g_image[300][300][3];

/**
 * Generate noise from random seed and store in g_image.
 */
void generate_noise_image() {
    // value distribution
    std::uniform_int_distribution<int> dist(0,255);
    // get color array randomly generated
    for (auto & i : g_image) {
        for (auto & j : i) {
            for (int & k : j) {
                k = dist(g_gen);
            }
        }
    }
}

/**
 * Initialize OpenGL Glut window.
 */
void init() {
    // load random noise into memory buffer
    generate_noise_image();
    //initialize window default values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,glutGet(GLUT_WINDOW_WIDTH),0,glutGet(GLUT_WINDOW_HEIGHT),-1,1);

}

/**
 * Puts image on screen, loaded from memory buffer stored as g_image.
 */
void display() {
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    // load image from memory buffer to paint on screen
    for (int i = 0; i < 300; ++i) {
        for (int j = 0; j < 300; ++j) {
            glColor3ub(g_image[i][j][0], g_image[i][j][1], g_image[i][j][2]);
            glVertex2i(i,j);
        }
    }

    glEnd();
    glFlush();
}


