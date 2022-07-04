#ifndef FORWARDEULERDEF
#define FORWARDEULERDEF

#include "AbstractODESolver.hpp"

class ForwardEuler: public AbstractODESolver
{
public:
    void Solver(double (*pFunc)(double, double), double (*pFuncExact)(double));
};

#endif