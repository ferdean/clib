#include <fstream>
#include <cmath>
#include <cassert>
#include "RK4.hpp"

#include <iostream>

void RK4::Solver(double (*pFunct)(double y, double t), double (*pFunctExact)(double)){
    
    double t_1 = initialTime;
    double y_1 = initialState;
    double h   = stepSize;
    
    std::ofstream write_result("RK4.dat");
    assert(write_result.is_open());

    write_result.precision(6);

    write_result << "t\t" << "y\t" << "yapprox\n";
    write_result << initialTime << " " << initialState << " " << initialState << "\n";

    double t = t_1;
    double y = y_1;

    double k1, k2, k3, k4;
    double increment;
    double y_exact, yn;

    while(t <= finalTime){
        t   += h; 

        k1 = h * (*pFunct)(y_1, t_1);
        k2 = h * (*pFunct)(y_1 + 0.5 * k1, t_1 + 0.5 * h);
        k3 = h * (*pFunct)(y_1 + 0.5 * k2, t_1 + 0.5 * h);
        k4 = h * (*pFunct)(y_1 + k3, t_1 + h);

        increment =  (k1 + 2 * k2 + 2 * k3 + k4)/6;

        y_exact = (*pFunctExact)(t);
        yn      = y_1 + increment;

        write_result << t << " " << y_exact << " " << yn << "\n";

        y_1  = yn;
        t_1  = t;
    }

    write_result.close();
}