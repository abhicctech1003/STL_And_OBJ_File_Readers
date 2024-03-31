#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"

using namespace std;

int main()
{
  // created object of StlReader
  reader readerObject;

  // created object of Triangulation
  Triangulation triangualtion;
  readerObject.readFile1(triangualtion);

  // created object of StlObj
  writer writerObj;
  writerObj.writerStl(triangualtion);
  return 0;
}
