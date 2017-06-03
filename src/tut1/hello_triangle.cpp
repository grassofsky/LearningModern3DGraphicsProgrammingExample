#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>

GLuint positionBufferObject;
GLuint theProgram;
const float vertexPositions[] = {
	0.75f, 0.75f, 0.0f, 1.0f,
	0.75f, -0.75f, 0.0f, 1.0f,
	-0.75f, -0.75f, 0.0f, 1.0f,
};

void InitializeVertexBuffer()
{
    glGenBuffers(1, &positionBufferObject);

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint CreateShader(GLenum eShaderType, const std::string &strShaderFilename)
{
    GLuint shader = glCreateShader(eShaderType);
    std::ifstream ifile(strShaderFilename.c_str());
    std::stringstream buffer;
    buffer << ifile.rdbuf();
    std::string contents(buffer.str());
    const char* pContents = contents.c_str();

    glShaderSource(shader, 1, &pContents, NULL);

    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar *strInfoLog = new GLchar[infoLogLength+1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Compile failure in %d shader: \n%s\n", eShaderType, strInfoLog);
        delete[] strInfoLog;
    }
    return shader;
}

GLuint CreateProgram(const std::vector<GLuint>& vecShader)
{
    GLuint program = glCreateProgram();
    for (size_t i=0; i<vecShader.size(); ++i)
    {
        glAttachShader(program, vecShader[i]);
    }

    glLinkProgram(program);

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        printf("Log length: %d\n", infoLogLength);
        GLchar *strInfoLog = new GLchar[infoLogLength+1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    for (size_t i=0; i<vecShader.size(); i++)
    {
        glDetachShader(program, vecShader[i]);
    }
    return program;
}


void InitializeProgram()
{
    std::vector<GLuint> shaderList;
    shaderList.push_back(CreateShader(GL_VERTEX_SHADER, "./../shader/tut1/hello_triangle.vert"));
    shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, "./../shader/tut1/hello_triangle.frag"));

    theProgram = CreateProgram(shaderList);
    std::for_each(shaderList.begin(), shaderList.end(), glDeleteShader);
}

void init()
{
    InitializeProgram();
    InitializeVertexBuffer();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(theProgram);
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,0,0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glUseProgram(0);
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    int width = 500;
    int height = 500;

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(300,200);
    int window = glutCreateWindow(argv[0]);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "glewInit failed: " << glewGetErrorString(err) << std::endl;
    }

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    /* glutKeyboardFunc(keyboard); */
    glutMainLoop();
    return 0;
}
