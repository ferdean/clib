#ifndef RKDEF
#define RKDEF

#include "AbstractODESolver.hpp"

class RK4: public AbstractODESolver
{
public:
    void Solver(double (*pFunc)(double, double), double (*pFuncExact)(double));
};

#endif