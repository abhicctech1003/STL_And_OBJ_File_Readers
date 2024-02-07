#include "../headers/STLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace Shapes3D;

STLWriter::STLWriter() {}
STLWriter::~STLWriter() {}

Triangulation STLWriter::writeSTL(std::string &filePath, Triangulation &triangulationObj)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();
    // for (const Point3D &point : points)
    // {
    //     outFile << point.x() << " " << point.y() << " " << point.z() << endl;
    // }

    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.index1()].x() << " " << points[triangle.index1()].y() << " " << points[triangle.index1()].z() << endl;
        // outFile << points[triangle.index2()].x() << " " << points[triangle.index2()].y() << " " << points[triangle.index2()].z() << endl;
        // outFile << points[triangle.index3()].x() << " " << points[triangle.index3()].y() << " " << points[triangle.index3()].z() << endl;
    }
    outFile.close();
    return triangulationObj;
}
