#ifndef MATRIX22CLASS
#define MATRIX22CLASS

#include <iostream>

class Matrix
{
private:
    //Internal contents/info of the class 
    //(in this case, the entries of the matrix)
    
    double mM11;
    double mM12;
    double mM21;
    double mM22;

public:
    //Constructors
    Matrix();
    Matrix(const Matrix&);
    Matrix(double, double, double, double);

    //Methods
    double Determinant() const;
    Matrix Inverse() const;
    Matrix Multiply(double) const;

    //Operators
    Matrix& operator=(const Matrix&);
    Matrix operator-() const;
    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    friend std::ostream& operator<<(std::ostream& output, const Matrix&);
};

#endif