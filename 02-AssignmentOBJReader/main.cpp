#include <iostream>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/ObjReader.h"
#include "./headers/ObjWriter.h"

int main()
{
    // Singleton instance for triangulation
    Triangulation &triangulation = Triangulation::getInstance();

    // Singleton instance for ObjReader
    ObjReader &reader = ObjReader::getInstance();
    reader.readObj(triangulation);

    // Singleton instance for ObjWriter
    ObjWriter &writer = ObjWriter::getInstance();
    writer.writeOBJ(triangulation);

    return 0;
}
