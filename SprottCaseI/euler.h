#pragma once

template <typename Fx, typename Fy, typename Fz>
void eulerStep(Fx dx, Fy dy, Fz dz,
               double& x, double& y, double& z, double h)
{
    double x_new = x + h * dx(x, y, z);
    double y_new = y + h * dy(x, y, z);
    double z_new = z + h * dz(x, y, z);
    x = x_new;
    y = y_new;
    z = z_new;
}