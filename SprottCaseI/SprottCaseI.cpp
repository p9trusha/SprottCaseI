#include <iostream>
#include "euler.h"
#include "midPoint.h"
#include "eulerCromer.h"

struct Params {
    double a     = -0.2;
    double b     = 1.0;
    double c     = 1.0;
    double d     = 1.0;
    double e     = 1.0;
    double f     = -1.0;
    double scale = 1e5;
};

Params p;

double dx(double x, double y, double z)
{
    return p.a * y * p.scale;
}

double dy(double x, double y, double z)
{
    return (p.b * x + p.c * z) * p.scale;
}

double dz(double x, double y, double z)
{
    return (p.d * x + p.e * y * y + p.f * z) * p.scale;
}

int main()
{
    double x0 = 0.0, y0 = 0.1, z0 = 0.0;
    double h = 1e-6;
    eulerSolve(dx, dy, dz, x0, y0, z0, h, 300, "csv/euler.csv");
    midPointSolve(dx, dy, dz, x0, y0, z0, h, 300, "csv/midPoint.csv");
    eulerCromerSolve(dx, dy, dz, x0, y0, z0, h, 300, "csv/eulerCromer.csv");
}