#pragma once
#include "Point3D.h"
namespace Shapes3D
{
    class Triangle
    {
    public:
        Triangle();
        Triangle(const int ind1, const int ind2, const int ind3);
        ~Triangle();

        int index1() const;
        int index2() const;
        int index3() const;

        void setindex1(int ind1);
        void setindex2(int ind2);
        void setindex3(int ind3);

    private:
        int mIndex1;
        int mIndex2;
        int mIndex3;
    };
}
