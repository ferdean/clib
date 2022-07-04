#include <iostream>

int main(int argc, char* argv[]){
   
    for(unsigned int x = 0; x<1e7; x++){
        double** A;
        double** B;
        double** C;

        A = new double* [2];
        B = new double* [2];
        C = new double* [2];

        for (unsigned int i = 0; i<2; i++){
            A[i] = new double [2];
            B[i] = new double [2];
            C[i] = new double [2];

            for (unsigned int j = 0; j<2; j++){
                A[i][j] = i + j;
                B[i][j] = i*j;

                C[i][j] = A[i][j] + B[i][j];
            }
        }

        for(unsigned int i = 0; i<2; i++){
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }

        delete[] A;
        delete[] B;
        delete[] C;
    }

    return 0;
}