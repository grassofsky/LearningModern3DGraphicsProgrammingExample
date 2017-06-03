#include <GL/glew.h>
#include <GL/glut.h>

#include "glsl_program.h"
#include "common.h"

int windowWidth=500;
int windowHeight=500;

GLuint positionBufferObject;
GLuint colorBufferObject;
GLuint vao;

const float vertexData[] = {
    0.0f,    0.5f, 0.0f, 1.0f,
    0.5f, -0.366f, 0.0f, 1.0f,
    -0.5f, -0.366f, 0.0f, 1.0f,
};

const float colorData[] = {
    1.0f,    0.0f, 0.0f, 1.0f,
    0.0f,    1.0f, 0.0f, 1.0f,
    0.0f,    0.0f, 1.0f, 1.0f, 
};

GLSLProgram program;

void InitializeVertexBuffer()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &positionBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, &colorBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorData), colorData, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
    program.AddShader(GL_VERTEX_SHADER, "./VertexColor.vert");
    program.AddShader(GL_FRAGMENT_SHADER, "./VertexColor.frag");
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

    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

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
