#ifndef MESHGL_H
#define MESHGL_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Mesh.h>

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>

class MeshGL
{
    public:
        GLfloat *vertArray;
        GLuint *faceArray;
        int vertLength;
        int faceLength;
        const void* getFaceArray();
        void draw();
        void printVertArray();
        void printFaceArray();
        void genColorArray();
        MeshGL(Mesh *convertThis);
        virtual ~MeshGL();
    protected:
    private:
};

#endif // MESHGL_H
