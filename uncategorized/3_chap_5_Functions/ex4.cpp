#include <iostream>
#include <cmath>
#include <cassert>

void computeStatistics(double*, double&, double&);

int main(int argc, char* argv[]){
    double* x;
    double mean, std;

    x = new double [10];

    x[0] = 1.0; x[1] = 8.0; x[2] = -7.2; x[3] = 0.0; x[4] = 1.0;
    x[5] = 1.5; x[6] = 6.0; x[7] = -1.0; x[8] = 8.0; x[9] = 1.2;

    computeStatistics(x, mean, std);

    std::cout << "mean = " << mean << "\t std = " << std;

    delete[] x;
}

void computeStatistics(double* x, double& mean, double& std){
    int size = 10;
    double sum = 0;

    for (unsigned int i = 0; i<size; i++){
        sum += x[i];
    }
    mean = sum/(double)(size);

    sum = 0;

    for (unsigned int j = 0; j<size; j++){
        sum += (x[j] - mean) * (x[j] - mean);
    }

    assert(size > 1);

    sum /= (double)(size - 1);
    
    std = sqrt(sum);   
}