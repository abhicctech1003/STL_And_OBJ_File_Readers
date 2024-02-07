#pragma once
#include "Triangulation.h"
#include <string>
#include <vector>
// using namespace std;
namespace Shapes3D
{
    class STLReader
    {
    public:
        STLReader();
        ~STLReader();
        // Shapes3D::Triangulation &triangulation();
        Triangulation readSTL(const std::string &filePath);

        // private:
        //     Triangulation mTriangulationOBJ;
    };
}