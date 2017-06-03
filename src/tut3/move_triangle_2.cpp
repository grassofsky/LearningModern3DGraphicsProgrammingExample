#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>
#include <cstring>

#include "glsl_program.h"
#include "common.h"

#define PI 3.1415927

int windowWidth = 500;
int windowHeight = 500;


GLSLProgram program;
GLuint positionBufferObject;
const float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

char vertexFilename[] = "./../shader/tut3/move_triangle_2.vert";
char fragFilename[] = "./../shader/tut3/move_triangle_1.frag";

void InitializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    // glBufferData with GL_STREAM_DRAW, so the content in the buffer
    // can be changed by function glBufferSubData
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
    InitializeVertexBuffer();
    InitializeProgram();
}

void ComputePositionOffsets(float &fXOffset, float &fYOffset)
{
    const float fLoopDuration = 5.0f;
    const float fScale = PI * 2.0f / fLoopDuration;

    float fElapsedTime = glutGet(GLUT_ELAPSED_TIME)/1000.0f;
    float fCurrTimeThroughLoop = std::fmod(fElapsedTime, fLoopDuration);

    fXOffset = std::cos(fCurrTimeThroughLoop * fScale) * 0.5f;
    fYOffset = std::sin(fCurrTimeThroughLoop * fScale) * 0.5f;
}

#define ARRAY_COUNT(x) sizeof(x)/sizeof(x[0])


void display()
{
    float fXOffset = 0.0f, fYOffset = 0.0f;
    ComputePositionOffsets(fXOffset, fYOffset);

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.UseProgram();
    GLuint offsetLoc = glGetUniformLocation(program.GetProgramID(), "offset");
    glUniform2f(offsetLoc, fXOffset, fYOffset);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
    glutSwapBuffers();
    glutPostRedisplay();
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
