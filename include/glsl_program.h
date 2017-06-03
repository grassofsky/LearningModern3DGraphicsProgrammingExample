/**@file	/home/zhongxiewei/workplace/learningModern3DGraphicProgramming/tut2/glsl_program.h
 * @author	zhongxiewei
 * @version	704
 * @date
 * 	Created:	05th Apr 2017
 * 	Last Update:	05th Apr 2017
 */
#ifndef _GLSL_PROGRAM_
#define _GLSL_PROGRAM_

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class GLSLProgram
{
public:
    bool AddShader(GLenum shaderType, const std::string& shaderFileName)
    {
        GLuint shader = glCreateShader(shaderType);

        std::ifstream ifile(shaderFileName.c_str());
        std::stringstream buffer;
        buffer << ifile.rdbuf();
        std::string contents(buffer.str());
        const char* pContents =  contents.c_str();

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
            fprintf(stderr, "Compile failure in %d shader: \n%s\n", shaderType, strInfoLog);
            delete[] strInfoLog;
            return false;
        }

        shaderList_.push_back(shader);
        return true;
    }

    bool LinkProgram()
    {
        bool result(true);
        program_ = glCreateProgram();
        for (size_t i=0; i<shaderList_.size(); ++i)
        {
            glAttachShader(program_, shaderList_[i]);
        }

        glLinkProgram(program_);

        GLint status;
        glGetProgramiv(program_, GL_LINK_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint infoLogLength;
            glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &infoLogLength);
            printf("Log length: %d\n", infoLogLength);
            GLchar *strInfoLog = new GLchar[infoLogLength+1];
            glGetProgramInfoLog(program_, infoLogLength, NULL, strInfoLog);
            fprintf(stderr, "Linker failure: %s\n", strInfoLog);
            delete[] strInfoLog;
            result = false;
        }

        for (size_t i=0; i<shaderList_.size(); i++)
        {
            glDetachShader(program_, shaderList_[i]);
            glDeleteShader(shaderList_[i]);
        }
        return result;
    }

    void UseProgram()
    {
        glUseProgram(program_);
    }

    GLuint GetProgramID()
    {
        return program_;
    }

private:
    std::vector<GLuint> shaderList_;
    GLuint program_;
};

#endif // _GLSL_PROGRAM_
