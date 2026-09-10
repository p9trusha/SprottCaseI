#pragma once

inline constexpr auto eulerCromerStep = [](auto dx, auto dy, auto dz,
                                           double& x, double& y, double& z, double h)
{
    x = x + h * dx(x, y, z);
    y = y + h * dy(x, y, z);
    z = z + h * dz(x, y, z);
};