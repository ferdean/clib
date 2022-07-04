#include "Matrix.hpp"

int main(int argc, char* argv[]){
    
    Matrix M(1, 0, 0, 1);
    
    std::cout << "M = \n" << M;
    std::cout << "\n\n" << "det(M) = " << M.Determinant();
    std::cout << "\ninv(M) = \n" << M.Inverse();

    Matrix M2(0, 1, 1, 2);

    std::cout<< "\n\n" << "M2 = \n" << M2;
    std::cout<< "\n\nM + M2 = \n\n" << M + M2;

    std::cout<<"\n\n 2*M = \n" << M.Multiply(2);
}