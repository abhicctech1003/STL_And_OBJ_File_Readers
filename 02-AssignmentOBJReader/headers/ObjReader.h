#pragma once
#include "Triangulation.h"

class ObjReader
{
    public:
        // singleton static method
         static ObjReader& getInstance();

        void readObj(Triangulation& triangulation);

    private:
        // Private constructor for singleton class
        ObjReader();

        // Singleton instance
        static ObjReader instance;
};
