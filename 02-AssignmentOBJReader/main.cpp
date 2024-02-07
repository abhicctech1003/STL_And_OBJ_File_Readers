#include<iostream>
#include"./headers/Point3D.h"
#include"./headers/Triangulation.h"
#include"./headers/Triangle.h"
#include"./headers/ObjReader.h"
#include"./headers/ObjWriter.h"
using namespace std;

int main()
{   
    ObjReader reader;
    Triangulation tri;

    reader.readObj(tri);
    ObjWriter writer;
    writer.writeOBJ(tri);
    return 1;

}