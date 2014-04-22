#include "OBJHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>

Mesh* OBJHandler::importObj(std::string filename){
    //Remember this if you have trouble creating pointers in the future.
    Mesh *cooble = new Mesh();
    std::ifstream reader;
    const int MAX_CHARS_PER_LINE = 64;
    const char* const DELIMETER = " ";

    reader.open(filename.c_str(), std::ifstream::in);
    if (!reader.good()){
        std::cout<<"OBJ File Read Error";
        return cooble;
    }

    while (!reader.eof()){
        //read line
        char buf[MAX_CHARS_PER_LINE];
        reader.getline(buf, MAX_CHARS_PER_LINE);

        if(buf[0] == 'v'){
            //std::cout<<strtok(buf, "v ");
            char * x = strtok(buf, "v ");
            //std::cout<<strtok(NULL, "v ");
            char * y = strtok(NULL, "v ");
            //std::cout<<strtok(NULL, "v ");
            char * z = strtok(NULL, "v ");

            //std::cout<<"tick"<<std::endl;

            //printf("tick");

            std::vector<float> triple;
            triple.push_back(atof(x));
            triple.push_back(atof(y));
            triple.push_back(atof(z));
            //std::cout<<x<<" "<<y<<" "<<z<<std::endl;
            //printf("%s,%s,%s\n",x,y,z);
            //printf("Floats To Push in Verts: %f,%f,%f\n", atof(x),atof(y),atof(z));
            cooble->pushVerts(triple);
        }
        else if (buf[0] == 'f'){
            char * p1 = strtok(buf, "f ");
            char * p2 = strtok(NULL, "f ");
            char * p3 = strtok(NULL, "f ");

            std::vector<int> face;

        //Put the vertex numbers for each face in a vector (minus 1 to correct for vector indices)
            face.push_back(atoi(p1)-1);
            face.push_back(atoi(p2)-1);
            face.push_back(atoi(p3)-1);

            cooble->pushFace(face);
        }

    }
    return cooble;
}


OBJHandler::OBJHandler()
{
    //ctor
}

OBJHandler::~OBJHandler()
{
    //dtor
}
