# STL Reader Assigment
This C++ project is designed for reading STL file data and writing it to the respective text files to plot that into gnu plot. The project follows a modular structure with separate header (.h) and implementation (.cpp) files for each class.

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/abhicctech1003/STL_And_OBJ_File_Readers.git
    ```

2. **Build the Project:**

    Open the project in your preferred C++ IDE or build using the command line.

3. **Run the Application:**

    Execute the built binary to run the application.

## Folder Structure
The project is organized into the following folders:

- **headers**: Contains header files for point, reader, shape, triangle, triangulation, writer class.

- **output**: Output contains execuatble.
 
- **src**: Contains implementation files corresponding to each header file.

- **main.cpp**: Main source file where the program execution starts.
 
## 1. Point3D
 
- Header: include/Point3D.h
 
- Implementation: src/Point3D.cpp
 
 ## 2. reader
 
- Header: include/reader.h
 
- Implementation: src/reader.cpp
 
## 3. Triangle
 
- Header: include/Triangle.h
 
- Implementation: src/Triangle.cpp

## 4. Triangulation
 
- Header: include/Triangulation.h
 
- Implementation: src/Triangulation.cpp

## 5. writer
 
- Header: include/writer.h
 
- Implementation: src/writer.cpp

### Source files content

- `Point3D.cpp`: Constructor, destructor, other methods, and operator overloading are defined.
- `reader.cpp`: Constructor, destructor & actual file reading from .OBJ code in method are defined.
- `Triangle.cpp`: Constructor, destructor, methods for triangle vertices & normals are defined.
- `Triangulation.cpp`: Constructor, destructor, methods for triangles, unique points & unique normals are defined.
- `writer.cpp`: Constructor, destructor & actual file writing into .STL code in method are defined.

### main files content

- Objects for reader, writer & triangulation are created.
- Methods in reader & writer are called.

### Steps to plot geometry on gnu plot
- Copy the path of text file of shape which we have to plot.
- In gnu plot give command as `splot 'file_path' w lp` to get shape plotted.
 

