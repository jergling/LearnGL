#include "Mesh.h"
#include <vector>

//vector< <> > contains verts, vector<float> contains 3 coordinates, may have some extra data (color, texture) at the end.
std::vector< std::vector<float> > verts;
std::vector< std::vector<int> > faces;

void Mesh::pushVerts(std::vector<float> triple){
    verts.push_back(triple);
}

void Mesh::pushFace(std::vector<int> face){
    faces.push_back(face);
}

std::vector<float> Mesh::getVertAt(int index){
    return verts.at(index);
}

std::vector<int> Mesh::getFaceAt(int index){
    return faces.at(index);
}

void Mesh::printFaceArray(){
    for(int i = 0; i < faces.size(); i++){
        printf("%i [%i]", i, faces[i][0]);
        printf(" [%i]", faces[i][1]);
        printf(" [%i]\n", faces[i][2]);
    }
}

Mesh::Mesh()
{
    //ctor
}

Mesh::~Mesh()
{
    //dtor
}
