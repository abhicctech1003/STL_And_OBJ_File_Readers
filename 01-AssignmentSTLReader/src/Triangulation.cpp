#include "..\headers\Triangulation.h"
using namespace Shapes3D;

Triangulation::Triangulation()
{
}

Triangulation::~Triangulation()
{
}

// Shapes3D::Triangulation Triangulation::triangulation()
// {
//     return Triangulation();
// }

vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints;
}

vector<Triangle> &Triangulation::triangles()
{
    return mTriangles;
}