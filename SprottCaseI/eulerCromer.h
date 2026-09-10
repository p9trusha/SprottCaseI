#pragma once

template <typename Fx, typename Fy, typename Fz>
void eulerCromerStep(Fx dx, Fy dy, Fz dz,
                     double& x, double& y, double& z, double h)
{
    x = x + h * dx(x, y, z);
    y = y + h * dy(x, y, z);
    z = z + h * dz(x, y, z);
}