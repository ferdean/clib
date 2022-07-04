#include <fstream>
#include <cmath>
#include <cassert>
#include "ForwardEuler.hpp"

void ForwardEuler::Solver(double (*pFunct)(double y, double t), double (*pFunctExact)(double)){
    
    double t_1 = initialTime;
    double y_1 = initialState;
    double h   = stepSize;
    
    std::ofstream write_result("ForwardEuler.dat");
    assert(write_result.is_open());

    write_result.precision(6);

    write_result << "t\t" << "y\t" << "yapprox\n";
    write_result << initialTime << " " << initialState << " " << initialState << "\n";

    double t = t_1;
    double y = y_1;

    double y_exact, yn;

    while(t <= finalTime){
        t   += h; 
        
        y_exact = (*pFunctExact)(t);
        yn      = y_1 + h * (*pFunct)(y_1, t_1);

        write_result << t << " " << y_exact << " " << yn << "\n";

        y_1  = yn;
        t_1  = t;
    }

    write_result.close();
}
