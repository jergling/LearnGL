#include "MeshGL.h"

GLfloat *vertArray;
GLuint *faceArray;
GLfloat *colorArray;
int vertLength;
int faceLength;

const void* MeshGL::getFaceArray(){
    return faceArray;
}

void MeshGL::draw(){
    //Vertex Array test, technically shouldn't be used
    int numFaces = sizeof(faceArray)/sizeof(faceArray[0]);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertArray);

    glDrawElements(GL_TRIANGLES, numFaces, GL_UNSIGNED_BYTE, faceArray );
    printf("Elements Drawn\n");
}

void MeshGL::printVertArray(){
    for(int i = 0; i < vertLength; ){
        printf("%i [%f]", i, vertArray[i]);
        printf(" [%f]", vertArray[i+1]);
        printf(" [%f]\n", vertArray[i+2]);
        i+=3;
    }
}

void MeshGL::printFaceArray(){
    for(int i = 0; i < vertLength; ){
        printf("%i [%i]", i, faceArray[i]);
        printf(" [%i]", faceArray[i+1]);
        printf(" [%i]\n", faceArray[i+2]);
        i+=3;
    }
}

void MeshGL::genColorArray(){
    colorArray = new GLfloat[faceLength];
    srand(time(NULL));
    for(int i = 0; i < faceLength; i++){
        colorArray[i] = rand() % 1;
    }
}

MeshGL::MeshGL(Mesh *convertThis)
{
    vertArray = new GLfloat[convertThis->verts.size()*3];
    vertLength = 0;
    faceArray = new GLuint[convertThis->faces.size()*3];
    //printf("Facearray immediately after alloc: %x", faceArray);
    faceLength = 0;

    //printf("Number of floats: %i\n Number of verts: %i\n", convertThis->verts.size()*3, convertThis->verts.size());
    //printf("Number of floats: %i\n Number of faces: %i\n", convertThis->faces.size()*3, convertThis->faces.size());

    for (int i = 0; i < convertThis->verts.size(); i++){
        //printf("Index %i, Vertex %f\n", i*3, convertThis->verts[i][0]);
        vertArray[i*3]   = convertThis->verts.at(i).at(0);
        //printf("Index %i, Vertex %f\n", i*3+1, convertThis->verts[i][1]);
        vertArray[i*3+1] = convertThis->verts.at(i).at(1);
        //printf("Index %i, Vertex %f\n", i*3+2, convertThis->verts[i][2]);
        vertArray[i*3+2] = convertThis->verts.at(i).at(2);
        vertLength+=3;
    }

    for (int i = 0; i < convertThis->faces.size(); i++){
        //printf("Index %i, Vertex %i\n", i*3, convertThis->faces[i][0]);
        faceArray[i*3]   = convertThis->faces.at(i).at(0);
        //printf("Index %i, Vertex %i\n", i*3+1, convertThis->faces[i][1]);
        faceArray[i*3+1] = convertThis->faces.at(i).at(1);
        //printf("Index %i, Vertex %i\n", i*3+2, convertThis->faces[i][2]);
        faceArray[i*3+2] = convertThis->faces.at(i).at(2);
        faceLength+=3;
    }

    printf("Size of VertArray: %i\n", sizeof(vertArray));

    printf("Facearray post load: %x\n", faceArray);
}

MeshGL::~MeshGL()
{
    //dtor
}
