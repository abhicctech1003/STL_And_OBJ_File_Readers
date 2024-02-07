#include <fstream>
#include <iostream>
#include <cmath>
#include "./headers/StlReader.h"
#include "./headers/STLtoOBj.h"
#include "./headers/STLwriter.h"

using namespace std;

int main()
{
  StlReader st;
  Triangulation triangualtion;
  st.readFile1(triangualtion );
 
  STLwriter obj;
  obj.writeSTLToFile(triangualtion);
  return 0;
}
