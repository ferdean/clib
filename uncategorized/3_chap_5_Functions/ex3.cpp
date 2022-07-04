#include <iostream>
#include <cstdlib>

void swapPointers(double*, double*);
void swapReference(double&, double&);

int main(int argc, char** argv){

    int method = atoi(argv[1]);

    double x = 10, y = 50;

    std::cout << "Original: \t x = " << x << " y = " << y;

    switch (method){
        case 0:
            swapPointers(&x, &y);
            break;
    
        case 1:
            swapReference(x, y);
            break;
        
        default: 
            std::cout << "\nError: Please select the desired method (0: pointers, 1: references).";
    }    

    std::cout << "\nSwaped: \t x = " << x << " y = " << y;

    return 0;
}

void swapPointers(double* p_x, double* p_y){
    double *p_k;
    p_k = new double;

    *p_k = *p_x;
    *p_x = *p_y;
    *p_y = *p_k;

    delete[] p_k;
}

void swapReference(double& x, double& y){
    double k = x;

    x = y;
    y = k;
}