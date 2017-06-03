#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

#include "common.h"


int main(int argc, char*argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(300,200);
    glutCreateWindow(argv[0]);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
    }

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
