#pragma once

inline constexpr auto eulerStep = [](auto dx, auto dy, auto dz,
                                     double& x, double& y, double& z, double h)
{
    double x_new = x + h * dx(x, y, z);
    double y_new = y + h * dy(x, y, z);
    double z_new = z + h * dz(x, y, z);
    x = x_new;
    y = y_new;
    z = z_new;
};