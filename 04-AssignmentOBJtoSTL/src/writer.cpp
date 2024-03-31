#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/writer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

writer :: writer()
{

}

writer :: ~writer()
{

}

void writer::writeOBJ(Triangulation &triangulation)
{
    std::ofstream outFile("cube.stl");

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    vector<Point3D> &points = triangulation.uniquePoints();

    vector<Triangle> &triangles = triangulation.triangles();
    vector<Point3D>& Normal=triangulation.uniqueNormal();
   
    // For writing Obj to Stl format
    outFile <<"solid exported "<<endl;
   
    for (const Triangle &triangle : triangles)
    {
        outFile << " face Normal "<<Normal[triangle.normalOfTriangle()].x()<< " " << Normal[triangle.normalOfTriangle()  ].y() << " " << Normal[triangle.normalOfTriangle()  ].z() << endl;
        outFile <<"      "<<"outer loop" <<endl;
        outFile <<"         " <<"vertex "<<points[triangle.v1()].x() << " " << points[triangle.v1()  ].y() << " " << points[triangle.v1()  ].z() << endl;
        outFile <<"         " <<"vertex "<< points[triangle.v2() ].x() << " " << points[triangle.v2()  ].y() << " " << points[triangle.v2()  ].z() << endl;
        outFile <<"         " <<"vertex "<< points[triangle.v3() ].x() << " " << points[triangle.v3()  ].y() << " " << points[triangle.v3()  ].z() << endl;
        outFile <<"      "<<"endloop" <<endl;
        outFile <<"     "<<"endfacet" <<endl;
    }
    
    outFile <<"End "<<endl;
    outFile.close();
}