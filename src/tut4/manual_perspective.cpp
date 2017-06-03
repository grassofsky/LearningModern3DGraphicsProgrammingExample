#include <GL/glew.h>
#include <GL/glut.h>

#include "glsl_program.h"
#include "common.h"

int windowWidth = 500;
int windowHeight = 500;


GLSLProgram program;
GLuint positionBufferObject;
const float vertexPositions[] = {
	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,

	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,

	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,

	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,




	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

};

char vertexFilename[] = "../shader/tut4/manual_perspective.vert";
char fragFilename[] = "../shader/tut4/manual_perspective.frag";

void InitializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
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

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CW);
}

void display()
{
    float cameraPos[4];
    cameraPos[0] = vertexPositions[0] + 0.5;
    cameraPos[1] = vertexPositions[1] + 0.5;
    cameraPos[2] = vertexPositions[2];
    cameraPos[3] = vertexPositions[3];

    float clipPos[4];
    clipPos[0] = cameraPos[0];
    clipPos[1] = cameraPos[1];

    clipPos[2] = cameraPos[2]*(1.0+3.0)/(1.f-3.f);
    clipPos.z = cameraPos.z*(fNear+fFar)/(fNear-fFar);
    clipPos.z += 2*fNear*fFar/(fNear-fFar);

    clipPos.w = -cameraPos.z;

    gl_Position = clipPos;

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    program.UseProgram();

    GLint offsetLoc = glGetUniformLocation(program.GetProgramID(), "offset");
    glUniform2f(offsetLoc, 0.5f, 0.5f);

    
	GLint frustumScaleUnif = glGetUniformLocation(program.GetProgramID(), "frustumScale");
	GLint zNearUnif = glGetUniformLocation(program.GetProgramID(), "zNear");
	GLint zFarUnif = glGetUniformLocation(program.GetProgramID(), "zFar");

    glUniform1f(frustumScaleUnif, 1.0f);
    glUniform1f(zNearUnif, 1.0f);
    glUniform1f(zFarUnif, 3.0f);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,0,(void*)(sizeof(vertexPositions)/2));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
