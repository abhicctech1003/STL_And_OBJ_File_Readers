#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include "../headers/Point3D.h"
#include "../headers/reader.h"
#include "../headers/Triangle.h"
#include "../headers/Triangulation.h"
using namespace std;

reader ::reader()
{

}
reader ::~reader()
{

}

void reader ::readFile1(Triangulation &triangualtion)
{
    std::ifstream readFromFile("cube.stl");

    map<Point3D, int> mapppedPoint3D;
    map<Point3D, int> mappedNormals;
    string line;
    vector<Triangle> tri;

    if (readFromFile.is_open())
    {

        int numberOfVertex = 1;
        int normalIndex = 1;
        int v1;
        int v2;
        int v3;
        int Normal;
        while (getline(readFromFile, line))
        {
            if (line.find("facet normal") != std::string::npos)
            {
                double x;
                double y;
                double z;
                istringstream facetNormal(line);
                string token1;
                string token2;
                facetNormal >> token1 >> token2 >> x >> y >> z;
                // Point3D object created
                Point3D point(x, y, z);

                // Find point is in map or not
                auto iterator = mappedNormals.find(point);

                // Add unique points if not found in map
                if (iterator == mappedNormals.end())
                {
                    mappedNormals[point] = triangualtion.uniqueNormal().size();
                    triangualtion.uniqueNormal().push_back(point);
                }

                normalIndex = mappedNormals[point];
            }

            if (line.find("vertex") != string::npos)
            {
                istringstream vertexStream(line);
                string token;
                double x, y, z;

                vertexStream >> token >> x >> y >> z;
                // x,y,z stored into object of Point3D
                Point3D point(x, y, z);

                auto it = mapppedPoint3D.find(point);

                if (it == mapppedPoint3D.end())
                {
                    triangualtion.uniquePoints().push_back(point);

                    mapppedPoint3D[point] = triangualtion.uniquePoints().size();
                }
                if (numberOfVertex == 1)
                {
                    v1 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
                else if (numberOfVertex == 2)
                {
                    v2 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
                else if (numberOfVertex == 3)
                {

                    v3 = mapppedPoint3D[point];
                    numberOfVertex++;
                }
            }

            if (numberOfVertex == 4)
            {

                Triangle T(v1, v2, v3, normalIndex);
                triangualtion.triangles().push_back(T);
                numberOfVertex = 1;
            }
        }
       
        readFromFile.close();
    }
}
