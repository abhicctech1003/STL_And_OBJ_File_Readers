#include "..\headers\Triangulation.h"
#include <map>
#include <vector>
#include <iostream>


// Initialization of static member instance for singleton class
Triangulation Triangulation::instance;

// Static method for accessing the singleton instance
Triangulation& Triangulation::getInstance() 
{
    return instance;
}

// To prevent outside initialization private constructor
Triangulation::Triangulation() 
{

}

Triangulation::~Triangulation() 
{

}

// triangles getter method 
std::vector<Triangle>& Triangulation::triangles()
{
    return mTriangles;
}

// To get reference vector of triangles
std::vector<Point3D>& Triangulation::uniquePoints()
{
    return mUniquePoints;
}

