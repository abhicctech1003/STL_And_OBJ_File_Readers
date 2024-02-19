#include "../headers/ObjReader.h"
#include "../headers/Triangulation.h"
#include "../headers/Triangle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

void ObjReader::readObj(Triangulation &triangulation)
{
    vector<Point3D> points;
    vector<Triangle> triangles;

    ifstream inputfile("Cube.obj");
    string line;

    while (getline(inputfile, line))
    {
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream singleline(line);
            string keyword;
            singleline >> keyword >> x >> y >> z;

            if (keyword == "v")
            {

                Point3D P1(x, y, z);

                points.push_back(P1);
            }
        }

        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream singleLine(line);
            string keyword;
            singleLine >> keyword >> x >> y >> z;

            if (keyword == "f")
            {

                int v1, v2, v3;
                v1 = x[0];
                v1 -= 48;
                v2 = y[0];
                v2 -= 48;
                v3 = z[0];
                v3 -= 48;

                Triangle T(v1, v2, v3);
                triangles.push_back(T);
            }
        }
    }

    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close();
}