#include <iostream>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/reader.h"
#include "./headers/writer.h"
using namespace std;

int main()
{
     // Triangulation object
    Triangulation triObj;

    // ObjReader object
    reader readerObj;

    readerObj.readObj(triObj);

    // ObjWriter object 
    writer writerObj;
    writerObj.writeOBJ(triObj);
    
    return 0;
}