#pragma once
#include "Triangulation.h"

class ObjWriter
{
    public:
        // singleton static method
        static ObjWriter& getInstance();

        void writeOBJ(Triangulation& triangulation);

    private:
        // Private constructor for singleton class
        ObjWriter();

        // Singleton instance
        static ObjWriter instance;
};
