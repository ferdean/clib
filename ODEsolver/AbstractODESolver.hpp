#ifndef PARENTODESOLVERDEF
#define PARENTODESOLVERDEF

class AbstractODESolver
{
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialState;
public:
    void SetStepSize(double);
    void SetInitialConds(double, double);
    void SetFinalTime(double);

    //virtual double RHS(double y, double t) = 0;
    virtual void Solver(double (*pFunction)(double, double), double (*pFunctionExact)(double)) = 0;
};

#endif