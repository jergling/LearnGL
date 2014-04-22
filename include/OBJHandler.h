#ifndef OBJHANDLER_H
#define OBJHANDLER_H
#include <Mesh.h>
#include <string>


class OBJHandler
{
    public:
        OBJHandler();
        virtual ~OBJHandler();
        static Mesh* importObj(std::string filename);
    protected:
    private:
};

#endif // OBJHANDLER_H
