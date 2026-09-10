#pragma once
#include <fstream>
#include <functional>

void eulerSolve(
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
        double x_new = x + h * dx(x, y, z);
        double y_new = y + h * dy(x, y, z);
        double z_new = z + h * dz(x, y, z);
        x = x_new;
        y = y_new;
        z = z_new;
        file << x << "," << y << "," << z << std::endl;
        time += h;
    }
}
