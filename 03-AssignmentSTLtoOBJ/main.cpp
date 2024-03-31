#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/reader.h"
#include "./headers/writer.h"
using namespace std;

int main()
{
  // StlReader object
  reader readerObj;

  // Triangulation object
  Triangulation triangualtion;
  readerObj.readFile1(triangualtion);

  // StlWriter object 
  writer writerObj;
  writerObj.writerStl(triangualtion);
  
  return 0;
}
