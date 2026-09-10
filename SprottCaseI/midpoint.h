#pragma once
#include <fstream>
#include <functional>

void midPointSolve(
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
        double k1x = dx(x, y, z);
        double k1y = dy(x, y, z);
        double k1z = dz(x, y, z);

        double k2x = dx(x + h / 2.0 * k1x, y + h / 2.0 * k1y, z + h / 2.0 * k1z);
        double k2y = dy(x + h / 2.0 * k1x, y + h / 2.0 * k1y, z + h / 2.0 * k1z);
        double k2z = dz(x + h / 2.0 * k1x, y + h / 2.0 * k1y, z + h / 2.0 * k1z);

        x += h * k2x;
        y += h * k2y;
        z += h * k2z;
        file << time << "," << x << "," << y << "," << z << std::endl;
        time += h;
    }
}
