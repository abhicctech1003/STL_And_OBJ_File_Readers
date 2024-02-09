#include "../headers/ObjReader.h"
#include <fstream>
#include <sstream>

// Initialization of static member instance for singleton class
ObjReader ObjReader::instance;

// Static method for accessing the singleton instance
ObjReader& ObjReader::getInstance() 
{
    return instance;
}

// To prevent outside initialization private constructor
ObjReader::ObjReader() 
{

}

// Perform triangulation and read obj
void ObjReader::readObj(Triangulation& triangulation)
 {
    std::vector<Point3D> points;
    std::vector<Triangle> triangles;

    std::ifstream inputfile("objfile\\cube.obj");
    std::string line;

    while (std::getline(inputfile, line)) 
    {
        if (line.find("v") != std::string::npos) 
        {
            double x, y, z;
            std::istringstream singleline(line);
            std::string keyword;
            singleline >> keyword >> x >> y >> z;
            if (keyword == "v") 
            {
                Point3D P1(x, y, z);
                points.push_back(P1);
            }
        }

        if (line.find("f") != std::string::npos) 
        {
            std::istringstream singleLine(line);
            std::string keyword;
            singleLine >> keyword;

            if (keyword == "f")
             {
                std::vector<int> vertices;
                std::string token;
                while (singleLine >> token)
                 {
                    // Split the token by '/'
                    std::istringstream tokenStream(token);
                    std::string subtoken;
                    while (std::getline(tokenStream, subtoken, '/'))
                    {
                        // Convert substring to integer and push it to vertices
                        vertices.push_back(std::stoi(subtoken));
                    }
                }

                // Extract first values
                int v1 = vertices[0];
                int v2 = vertices[3];
                int v3 = vertices[6];

                Triangle T(v1, v2, v3);
                triangles.push_back(T);
            }
        }
    }

    // Populated vectors assigned to Triangulation object
    triangulation.triangles() = triangles;
    triangulation.uniquePoints() = points;

    inputfile.close();
}
