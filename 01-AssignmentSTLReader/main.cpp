#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"

using namespace Shapes3D;
typedef vector<Triangle> Triangles;

int main()
{
    std::string inputFilePath = "D:/rashmi_workspace/CPP/Project3_3DShapes_Triangulation/stlFiles/sphere.stl";
    std::string outputFilePath = "outputTextFile.txt";

    // STLReader stlReader;
    // stlReader.readSTL();
    Shapes3D::STLReader stlReader;
    Triangulation triangulation = stlReader.readSTL(inputFilePath);

    // Triangulation triangulation = stlReader.triangulation();
    // Triangles triangles = triangulation.triangles();
    // std::vector<Point3D> uniquePoints = triangulation.uniquePoints();

    Shapes3D::STLWriter stlWriter;
    stlWriter.writeSTL(outputFilePath, triangulation);

    return 0;
}
