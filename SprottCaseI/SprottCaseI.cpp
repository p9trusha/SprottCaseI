#include <iostream>
#include "euler.h"

double dx(double y)
{
    return -0.2 * y;
}

double dy(double x, double z)
{
    return x + z;
}

double dz(double x, double y, double z)
{
    return x + y * y - z;
}

int main()
{
    eulerSolve(dx, dy, dz, 1, 1, 1, 0.01, 1000);
}
