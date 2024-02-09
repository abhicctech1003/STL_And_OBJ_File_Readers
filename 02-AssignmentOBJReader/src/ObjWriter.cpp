#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/ObjWriter.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Initialization of static member instance for singleton class
ObjWriter ObjWriter::instance;

// Static method for accessing the singleton instance
ObjWriter& ObjWriter::getInstance() 
{
    return instance;
}

// To prevent outside initialization private constructor
ObjWriter::ObjWriter() 
{

}

// Method to write triangulation data to OBJ file
void ObjWriter::writeOBJ(Triangulation& triangulation) 
{
    std::ofstream outFile("./textfiles/Cube.txt"); 

    // Check if file is successfully opened
    if (!outFile.is_open()) 
    {
        // Error
        std::cout << "File is not opening" << std::endl; 
        return;
    }

    // Get reference to vector of unique points
    std::vector<Point3D>& points = triangulation.uniquePoints(); 

    // Get reference to vector of triangles
    std::vector<Triangle>& triangles = triangulation.triangles(); 

    for (const Triangle& triangle : triangles)
    {
        outFile << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << std::endl;
        outFile << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << std::endl;
        outFile << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << std::endl;
    }
    outFile.close();
}