#pragma once
#include <fstream>
#include <functional>

void eulerCromerSolve(
    std::function<double(double, double, double)> dx,
    std::function<double(double, double, double)> dy,
    std::function<double(double, double, double)> dz,
    double x0, double y0, double z0, double h, int N,
    const std::string& filename)
{
    std::ofstream file(filename);
    file << "time,x,y,z" << std::endl;

    double x = x0, y = y0, z = z0;
    double time = 0.0;
    for (int i = 0; i < N; i++)
    {
        x = x + h * dx(x, y, z);
        y = y + h * dy(x, y, z);
        z = z + h * dz(x, y, z);
        file << time << "," << x << "," << y << "," << z << std::endl;
        time += h;
    }
}
