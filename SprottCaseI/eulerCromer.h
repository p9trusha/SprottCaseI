#pragma once
#include <fstream>

template <typename Fx, typename Fy, typename Fz>
void eulerCromerSolve(
    Fx dx, Fy dy, Fz dz,
    double x0, double y0, double z0,
    double h, int N,
    const std::string& filename)
{
    std::ofstream file(filename);
    double x = x0, y = y0, z = z0;
    for (int i = 0; i < N; i++)
    {
        x = x + h * dx(y);
        y = y + h * dy(x, z);
        z = z + h * dz(x, y, z);
        file << x << "," << y << "," << z << std::endl;
    }
}
