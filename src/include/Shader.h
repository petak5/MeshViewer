//
// Created by Peter Urgoš on 27/03/2020.
//

#ifndef MESHVIEWER_SHADER_H
#define MESHVIEWER_SHADER_H

class Shader {
public:
    Shader(const std::string pathToVertexShader, const std::string pathToFragmentShader);

    unsigned int getVertexShader();
    unsigned int getFragmentShader();
    unsigned int getShaderProgram();

private:
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;

    unsigned int LoadVertexShader(const std::string pathToShader);
    unsigned int LoadFragmentShader(const std::string pathToShader);
    unsigned int CreateShaderProgram();
    std::string ReadFile(const std::string path);
};

#endif //MESHVIEWER_SHADER_H
