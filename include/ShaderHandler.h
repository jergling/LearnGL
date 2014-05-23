#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class ShaderHandler
{
    public:
        GLuint loadShaders(const char* vertexpath, const char* fragmentpath);
        ShaderHandler();
        virtual ~ShaderHandler();
    protected:
    private:
};

#endif // SHADERHANDLER_H
