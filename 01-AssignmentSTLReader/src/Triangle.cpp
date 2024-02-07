#include "../headers/Triangle.h"
using namespace Shapes3D;

Triangle::Triangle() {}
Triangle::Triangle(const int ind1, const int ind2, const int ind3) : mIndex1(ind1), mIndex2(ind2), mIndex3(ind3) {}
Triangle::~Triangle() {}

int Triangle::index1() const
{
    return mIndex1;
}

int Triangle::index2() const
{
    return mIndex2;
}

int Triangle::index3() const
{
    return mIndex3;
}

void Triangle::setindex1(int ind1)
{
    mIndex1 = ind1;
}

void Triangle::setindex2(int ind2)
{
    mIndex2 = ind2;
}

void Triangle::setindex3(int ind3)
{
    mIndex3 = ind3;
}