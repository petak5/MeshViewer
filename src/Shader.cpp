//
// Created by Peter Urgoš on 27/03/2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <glad/glad.h>

#include "include/Shader.h"

Shader::Shader(const std::string pathToVertexShader, const std::string pathToFragmentShader)
{
    vertexShader = LoadVertexShader(pathToVertexShader);
    fragmentShader = LoadFragmentShader(pathToFragmentShader);
    shaderProgram = 0;
}

unsigned int Shader::getVertexShader()
{
    return vertexShader;
}
unsigned int Shader::getFragmentShader()
{
    return fragmentShader;
}

unsigned int Shader::getShaderProgram()
{
    if (shaderProgram == 0)
    {
        CreateShaderProgram();
    }

    return shaderProgram;
}

unsigned int Shader::LoadVertexShader(const std::string pathToShader)
{
    std::string src = ReadFile(pathToShader);
    const char* vertexShaderSource = src.c_str();

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    else
    {
        return vertexShader;
    }
}
unsigned int Shader::LoadFragmentShader(const std::string pathToShader)
{
    std::string src = ReadFile(pathToShader);
    const char* fragmentShaderSource = src.c_str();

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }
    else
    {
        return fragmentShader;
    }
}

void Shader::CreateShaderProgram()
{
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    //glDeleteShader(vertexShader);
    //glDeleteShader(fragmentShader);
}

std::string Shader::ReadFile(const std::string path)
{
    std::ifstream stream(path);

    if (!stream)
    {
        std::cout << "Error: failed to open file `" << path << "`\n" << std::endl;
    }
    std::string line;

    std::string content;

    while (getline(stream, line))
    {
        content.append(line + '\n');
    }

    return content;
}