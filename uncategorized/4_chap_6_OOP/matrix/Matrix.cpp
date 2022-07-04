#include "Matrix.hpp"

#include <cmath>
#include <cassert>

//+++++++ Constructors ++++++++++++++++++++++++++++++
//Override empty constructor
Matrix::Matrix(){
    mM11 = 0.0; mM12 = 0.0;
    mM21 = 0.0; mM22 = 0.0;
}

//Override copy constructor 
Matrix::Matrix(const Matrix& copyMatrix){
    mM11 = copyMatrix.mM11; mM12 = copyMatrix.mM12;
    mM21 = copyMatrix.mM21; mM22 = copyMatrix.mM22;
}

//Override values constructor 
Matrix::Matrix(double a, double b, double c, double d){
    mM11 = a;  mM12 = b;
    mM21 = c;  mM22 = d;
}

//+++++++ Methods ++++++++++++++++++++++++++++++++++++
//Determinant computation
double Matrix::Determinant() const{
    return mM11*mM22 - (mM12*mM21);
}

//Inverse
Matrix Matrix::Inverse() const{

    double det = Determinant();
    assert(fabs(det) > 1E-6);

    double a =   mM22/det;
    double b = - mM21/det;  
    double c = - mM12/det;
    double d =   mM11/det;

    return Matrix(a, b, c, d);
}

//Multiplication 
Matrix Matrix::Multiply(double a) const{
    return Matrix(a*mM11, a*mM12, a*mM21, a*mM22);
}


//+++++++ Operators ++++++++++++++++++++++++++++++++++++++
std::ostream& operator<<(std::ostream& output, const Matrix& M){
    output << M.mM11 << "\t" << M.mM12 << "\n"
           << M.mM21 << "\t" << M.mM22;
    
    return output;
}

Matrix& Matrix::operator=(const Matrix& A){
    mM11 = A.mM11; mM12 = A.mM12;
    mM21 = A.mM21; mM22 = A.mM22;
    
    return *this;
}

Matrix Matrix::operator-() const{
    Matrix M;

    M.mM11 = -mM11; M.mM12 = -mM12;
    M.mM21 = -mM21; M.mM22 = -mM22;

    return M;
}

Matrix Matrix::operator-(const Matrix& M) const{
    
    Matrix M2;

    M2.mM11 = M.mM11 - mM11; M2.mM12 = M.mM12 - mM12;
    M2.mM21 = M.mM21 - mM21; M2.mM22 = M.mM22 - mM22;

    return M2;
}

Matrix Matrix::operator+(const Matrix& M) const{
    
    Matrix M2;

    M2.mM11 = M.mM11 + mM11; M2.mM12 = M.mM12 + mM12;
    M2.mM21 = M.mM21 + mM21; M2.mM22 = M.mM22 + mM22;

    return M2;
}