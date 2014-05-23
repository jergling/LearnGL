#ifndef MESH_H
#define MESH_H
#include <vector>
#include <stdio.h>

class Mesh
{
    public:
        Mesh();
        virtual ~Mesh();
        void pushVerts(std::vector<float> triple);
        void pushFace(std::vector<int> face);
        std::vector<float> getVertAt(int index);
        std::vector<int> getFaceAt(int index);
        void printFaceArray();
        std::vector< std::vector<float> > verts;
        std::vector< std::vector<int> > faces;
    protected:
    private:

};

#endif // MESH_H
