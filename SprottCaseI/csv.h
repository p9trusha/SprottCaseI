#pragma once
#include <fstream>
#include <ostream>
#include <string>

void writeHeader(std::ostream& out)
{
    out << "time,x,y,z\n";
}

void writeRow(std::ostream& out, double t, double x, double y, double z)
{
    out << t << "," << x << "," << y << "," << z << "\n";
}

template <typename Step, typename Fx, typename Fy, typename Fz>
void solve(Step step, const Fx& dx, const Fy& dy, const Fz& dz,
           double x0, double y0, double z0,
           double h, double timeEnd, int saveEvery,
           const std::string& filename)
{
    double x = x0, y = y0, z = z0;
    int steps = static_cast<int>(timeEnd / h);

    std::ofstream file(filename);
    writeHeader(file);

    double time = 0.0;
    for (int i = 0; i < steps; i++)
    {
        step(dx, dy, dz, x, y, z, h);
        if (i % saveEvery == 0)
        {
            writeRow(file, time, x, y, z);
        }
        time += h;
    }
}