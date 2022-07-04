#include <iostream>
#include <cmath>

#include "AbstractODESolver.hpp"
#include "ForwardEuler.hpp"
#include "RK4.hpp"

double RHS(double, double);
double Exact(double);

int main(int argc, char* argv[]){

    AbstractODESolver* pODE   = new ForwardEuler;
    AbstractODESolver* pODERK = new RK4;

    double h  = 1e-1;
    double t0 = 0.0;
    double y0 = 2.0;
    double T  = 1.0;

    pODE -> SetInitialConds(t0, y0);
    pODE -> SetFinalTime(T);
    pODE -> SetStepSize(h);

    pODE -> Solver(RHS, Exact);

    pODERK -> SetInitialConds(t0, y0);
    pODERK -> SetFinalTime(T);
    pODERK -> SetStepSize(h);

    pODERK->Solver(RHS, Exact);

    delete[] pODE;
}


double RHS(double y, double t){
    return 1 + t;
}

double Exact(double t){
    return 0.5 * (t*t + 2*t + 4);
}