#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
    
    double* X;
    double* Y;
    float sum = 0.0;

    for (unsigned int j = 0; j < 1e7; j++){
        X = new double [3];
        Y = new double [3];
        sum = 0.0;

        for (unsigned int i = 0; i<3; i++){
            X[i] = (double)(i + 1);
            Y[i] = 2.0 * X[i];

            sum += X[i] * Y[i];
        }

        delete[] X;
        delete[] Y;
    }
    
    std::cout << sum;

    return 0;
}