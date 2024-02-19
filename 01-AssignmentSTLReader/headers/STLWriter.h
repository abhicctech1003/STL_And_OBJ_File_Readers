#pragma once
#include "../headers/Triangulation.h"
#include <string>

namespace Shapes3D
{
    class STLWriter
    {
    public:
        STLWriter();
        ~STLWriter();

        Triangulation writeSTL(std::string &filePath, Triangulation &triangulationObj);
    };
}
