#include <iostream>
#include <cassert>

void multiply(double**, double**, double**, int, int, int, int);

int main(int argc, char* argv[]){
    double** A;
    double** B;
    double** C;

    int nRowA = 2, nRowB = 3;
    int nColA = 3, nColB = 2;

    A = new double* [nRowA];
    B = new double* [nRowB];
    C = new double* [nRowA];

    for (unsigned int i = 0; i < nRowA; i++){
        A[i] = new double [nColA];
        C[i] = new double [nColB];
    }

    for (unsigned int i = 0; i < nRowB; i++){
        B[i] = new double [nColB];
    }

    A[0][0] = 0; A[0][1] = 1; A[1][0] = 1; A[1][1] = 2; A[0][2] = 1; A[1][2] = 1;
    B[0][0] = 0; B[0][1] = 0; B[1][0] = 0; B[1][1] = 1; B[2][0] = 1; B[2][1] = 1;

    multiply(A, B, C, nRowA, nColA, nRowB, nColB);

    std::cout << "C = \n";
    for (unsigned int i = 0; i < nRowA; i++){
        for (unsigned int j = 0; j < nColB; j++){
            std::cout << C[i][j] << "\t";
        }
        std::cout << "\n";
    }


    for (unsigned int i = 0; i < nRowA; i++){
        delete[] A[i];
        delete[] C[i];
    }

    for (unsigned int i = 0; i < nRowB; i++){
        delete[] B[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

void multiply(double** A, double** B, double** C, 
              int nRowA, int nColA, int nRowB, int nColB){

    assert(nColA == nRowB);

    for (unsigned int i = 0; i < nRowA; i++){
        for (unsigned int j = 0; j < nColB;  j++){
            C[i][j] = 0;
            for (unsigned int k = 0; k < nColA; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

}