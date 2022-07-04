#include "AbstractODESolver.hpp"

void AbstractODESolver::SetInitialConds(double t0, double x0){
    initialState = x0;
    initialTime  = t0;
}

void AbstractODESolver::SetStepSize(double h){
    stepSize = h;
}

void AbstractODESolver::SetFinalTime(double T){
    finalTime = T;
}

