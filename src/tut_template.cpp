#include <GL/glew.h>
#include <GL/glut.h>

#include "glsl_program.h"
#include "common.h"

int windowWidth = 500;
int widthHeight = 500;


GLSLProgram program;
GLuint positionBufferObject;
const float vertexPositions[] = {
};

char vertexFilename[] = "";
char fragFilename[] = "";

void InitializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STREAM_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
    program.AddShader(GL_VERTEX_SHADER,vertexFilename);
    program.AddShader(GL_FRAGMENT_SHADER,fragFilename);
    program.LinkProgram();
}

void init()
{
    InitializeProgram();
    InitializeVertexBuffer();
}

void display()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.UseProgram();

    glUseProgram(0);
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void mouseClick(int button, int state, int x, int y)
{

}

void mouseMotion(int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{

}

#include "main.cpp"
