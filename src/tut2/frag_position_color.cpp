#include <GL/glew.h>
#include <GL/glut.h>

#include "glsl_program.h"
#include "common.h"

int windowWidth=500;
int windowHeight=500;

GLuint positionBufferObject;
const float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

GLSLProgram program;

void InitializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
    program.AddShader(GL_VERTEX_SHADER, "./../shader/tut2/FragPosition.vert");
    program.AddShader(GL_FRAGMENT_SHADER, "./../shader/tut2/FragPosition.frag");
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

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
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
