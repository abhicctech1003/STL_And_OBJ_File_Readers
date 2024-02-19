#pragma once
#include <vector>
#include "Triangle.h"
#include "Point3D.h"

class Triangulation
{
    public:
        // singleton static method
        static Triangulation& getInstance();

        ~Triangulation();

        // triangles getter method 
        std::vector<Triangle>& triangles();

        // unique points getter method for 
        std::vector<Point3D>& uniquePoints();

    private:
        // Private constructor for singleton class
        Triangulation();  

        // Singleton instance
        static Triangulation instance;

        std::vector<Triangle> mTriangles;
        std::vector<Point3D> mUniquePoints;
};
