#pragma once
#include <iostream>

template <typename Fx, typename Fy, typename Fz>
void midPointSolve(
    Fx dx, Fy dy, Fz dz,
    double x0, double y0, double z0,
    double h, int N
)
{
    double x = x0, y = y0, z = z0;
    for (int i = 0; i < N; i++)
    {
        double k1x = dx(y);
        double k1y = dy(x, z);
        double k1z = dz(x, y, z);

        double k2x = dx(y + h / 2.0 * k1y);
        double k2y = dy(x + h / 2.0 * k1x, z + h / 2.0 * k1z);
        double k2z = dz(x + h / 2.0 * k1x, y + h / 2.0 * k1y, z + h / 2.0 * k1z);

        x += h * k2x;
        y += h * k2y;
        z += h * k2z;
        std::cout << i << " " << x << " " << y << " " << z << std::endl;
    }
}
