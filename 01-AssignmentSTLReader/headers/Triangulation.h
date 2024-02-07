#pragma once
#include "Triangle.h"
#include <vector>
using namespace std;

namespace Shapes3D
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        // Triangulation triangulation();
        vector<Point3D> &uniquePoints();
        vector<Triangle> &triangles();

    private:
        vector<Point3D> mUniquePoints;
        vector<Triangle> mTriangles;
    };
}
