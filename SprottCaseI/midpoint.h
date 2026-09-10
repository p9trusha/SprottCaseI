#pragma once

template <typename Fx, typename Fy, typename Fz>
void midPointStep(Fx dx, Fy dy, Fz dz,
                  double& x, double& y, double& z, double h)
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
}