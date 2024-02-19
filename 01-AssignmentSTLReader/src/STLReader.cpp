// #include "../headers/STLReader.h"
// #include "../headers/Triangulation.h"
// // #include "../headers/CustomComparator.h"
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <map>
// using namespace std;
// using namespace Shapes3D;

// STLReader::STLReader() {}

// STLReader::~STLReader() {}

// Triangulation STLReader::readSTL(const std::string &filePath)
// {
//     Triangulation triangulationObj;
//     vector<Triangle> triangles;

//     ifstream file(filePath);

//     if (!file.is_open())
//     {
//         cout << "Error while opening the file." << endl;
//     }

//     string line;
//     vector<Point3D> points;
//     map<Point3D, int> pointIndexMap;

//     const double tolerance = 1e-6; // Adjust this tolerance value as needed

//     while (getline(file, line))
//     {
//         istringstream iss(line);
//         string token;
//         iss >> token;
//         int count = 0;

//         if (token == "vertex")
//         {
//             double x, y, z;
//             iss >> x >> y >> z;

//             Point3D point(x, y, z);

//             // Check if the point is already present with a tolerance
//             bool pointExists = false;
//             for (const auto &pair : pointIndexMap)
//             {
//                 if (abs(pair.first.x() - point.x()) < tolerance &&
//                     abs(pair.first.y() - point.y()) < tolerance &&
//                     abs(pair.first.z() - point.z()) < tolerance)
//                 {
//                     pointExists = true;
//                     break;
//                 }
//             }

//             if (!pointExists)
//             {
//                 int index = points.size();
//                 pointIndexMap[point] = index;
//                 points.push_back(point);
//             }
//             else
//             {
//                 cout << "Point already present in map." << endl;
//                 count++;
//             }

//             if (points.size() % 3 == 0)
//             {
//                 triangles.push_back(Triangle(points.size() - 3, points.size() - 2, points.size() - 1));
//             }
//         }
//     }

//     cout << "Points reading completed successfully!" << endl;

//     triangulationObj.uniquePoints() = points;
//     triangulationObj.triangles() = triangles;

//     return triangulationObj;
// }
#include "../headers/STLReader.h"
#include "../headers/Triangulation.h"
// #include "../headers/CustomComparator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
using namespace Shapes3D;

STLReader::STLReader() {}

STLReader::~STLReader() {}

Triangulation STLReader::readSTL(const std::string &filePath)
{
    Triangulation triangulationObj;

    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Error while opening the file." << endl;
    }

    string line;
    vector<Point3D> points;
    vector<Triangle> triangles;
    map<Point3D, int> pointIndexMap;
    int count = 0;
    while (getline(file, line))
    {
        istringstream iss(line);
        string token;
        iss >> token;

        if (token == "vertex")
        {
            double x, y, z;
            iss >> x >> y >> z;

            Point3D point(x, y, z);

            auto it = pointIndexMap.find(point);
            if (it == pointIndexMap.end())
            {
                int index = points.size();
                pointIndexMap[point] = index;
                points.push_back(point);
            }
            else
            {
                cout << "Point already present in map." << endl;
                count++;
            }

            int index1 = pointIndexMap[point];
            int index2 = pointIndexMap[point];
            int index3 = pointIndexMap[point];
            // triangles.push_back(Triangle(pointIndexMap[point]));
            triangles.push_back(Triangle(index1, index2, index3));
            // pointIndexMap[Point3D(x + 1.0, y, z)] = index + 1;
            // pointIndexMap[Point3D(x + 2.0, y, z)] = index + 2;

            // triangles.push_back(Triangle(index1, index2, index3));

            // if (points.size() >= 3 && points.size() % 3 == 0)
            // {
            //     triangles.push_back(Triangle(points.size() - 3, points.size() - 2, points.size() - 1));
            // }

            // // int index2 = pointIndexMap[point2];
            // // int index3 = pointIndexMap[point3];

            // triangles.push_back(Triangle(index, index + 1, index + 2));
            // pointIndexMap[Point3D(x + 1.0, y, z)] = index + 1;
            // pointIndexMap[Point3D(x + 2.0, y, z)] = index + 2;

            // triangles.push_back(Triangle(index1, index2, index3));
        }
    }
    cout << "Points reading completed successfully!" << endl;
    cout << count << endl;

    triangulationObj.uniquePoints() = points;
    triangulationObj.triangles() = triangles;

    return triangulationObj;
}
