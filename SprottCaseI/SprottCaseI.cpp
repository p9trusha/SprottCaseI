#include <iostream>
#include "euler.h"
#include "midPoint.h"
#include "eulerCromer.h"
#include "csv.h"

struct Params {
    double a     = -0.2;
    double b     = 1.0;
    double c     = 1.0;
    double d     = 1.0;
    double e     = 1.0;
    double f     = -1.0;
    double scale = 1e5;
};

int main()
{
    Params p;
    p.a = -0.2;
    p.scale = 1e5;

    auto dx = [&p](double x, double y, double z) { return p.a * y * p.scale; };
    auto dy = [&p](double x, double y, double z) { return (p.b * x + p.c * z) * p.scale; };
    auto dz = [&p](double x, double y, double z) { return (p.d * x + p.e * y * y + p.f * z) * p.scale; };

    double x0 = 0.0, y0 = 0.1, z0 = 0.0;
    const double h = 1e-6;
    const double timeEnd = 20.0;
    const int saveEvery = 1000;

    auto euler = [](auto dx, auto dy, auto dz, double& x, double& y, double& z, double h)
    {
        eulerStep(dx, dy, dz, x, y, z, h);
    };
    auto midPoint = [](auto dx, auto dy, auto dz, double& x, double& y, double& z, double h)
    {
        midPointStep(dx, dy, dz, x, y, z, h);
    };
    auto eulerCromer = [](auto dx, auto dy, auto dz, double& x, double& y, double& z, double h)
    {
        eulerCromerStep(dx, dy, dz, x, y, z, h);
    };

    solve(euler, dx, dy, dz, x0, y0, z0, h, timeEnd, saveEvery, "csv/euler.csv");
    solve(midPoint, dx, dy, dz, x0, y0, z0, h, timeEnd, saveEvery, "csv/midPoint.csv");
    solve(eulerCromer, dx, dy, dz, x0, y0, z0, h, timeEnd, saveEvery, "csv/eulerCromer.csv");
}