// 5.11_Exercises_5.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*5.9 Write a module for solving the 3 × 3 linear system Au = b where A is nonsingular*/
    /*  1. Make matrix
        2. Make vector
        3. Evaluate determinant
        4. Form cofactor matrix
        5. Transpose cofactor matrix to obtain adjoint
        6. divide throught the adjoint by the determinant
        7. Multiply A^-1 matrix x b column vector = new column vector for x values*/
#include <iostream>
#include <cmath>

using namespace std;

//Function prototypes for formation and deletion of matrix and vector
double** MakeMatrix(int);
double* MakeVector(int);
void EnterMatrixElements(double**, int);
void DeleteMatrix(double**, int);
void DeleteVector(double*);
void MakeDummyVector(double*);
//Function prototypes for display functions for matrix and vector
void DisplayMatrix(double**, int, int);
void DisplayVector(double*, int);

//Function prototypes to obtain inverse of square matrix functions
double ThreebyThreedeterminant(double**);           // Evaluate determinant of matrix
double TwobyTwodeterminant(double, double, double, double);
double** InverseA(double**);
                                        //Using x = A^-1 . b (b = column vector/matrix formed from linear equation numbers)
double* Mutiply(double**, double*, double*, int, int, int);

double** MakeMatrix(int size)
{
    double** matrix;
    matrix = new double* [size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
    }
    return matrix;
}
void MakeDummyVector(double* vector)
{
    for (int i = 0; i < 3; i++)
    {
        vector[i] = 0;
    }
}
void EnterMatrixElements(double** matrix, int size)
{
    cout << "What data would you like to enter for the matrix?" << endl;
    cout << "The matrix has a size of " << size * size << " elements" << endl;
    double temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "What is number you would like to enter?" << endl;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }
    DisplayMatrix(matrix, size, size);
}
double* MakeVector(int size)
{
    //Dynamically allocate memory for vector array
    double* vector = new double[size];
    return vector;
}

void EnterVectorElements(double* vector)
{
    cout << "Enter the values for each element in your column vector" << endl;
    //Enter values for vector array elements
    for (int i = 0; i < 3; i++)
    {
        cin >> vector[i];
    }
}

void DeleteMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void DeleteVector(double* vector)
{
    delete[] vector;
}
void DisplayMatrix(double** matrix, int rows, int columns)
{
    cout << "{";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    cout << "}";
}
void DisplayVector(double* vector, int size)
{
    cout << "The elements of the vector are {";
    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << endl;
    }
    cout << "}";
}
double TwobyTwodeterminant(double a, double b, double c, double d)
{
    return ((a * d) - (b * c));
}
double ThreebyThreedeterminant(double** A)
{
    double determinant =    A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]))
                        -   A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0]))
                        +   A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0]));

    return determinant;
}
double** InverseA(double** A) 
{
    double** cofactor = MakeMatrix(3);
    double** cofactor_transposed = MakeMatrix(3);
    double** A_minus_1 = MakeMatrix(3);
    double** tempmatrix = MakeMatrix(3);

    //Form co factor matrix by recursion using the 2 x 2 determinant function using the A matrix
    cofactor[0][0] =      TwobyTwodeterminant(A[1][1], A[1][2], A[2][1], A[2][2]);
    cofactor[0][1] = -1 * TwobyTwodeterminant(A[1][0], A[1][2], A[2][0], A[2][2]);
    cofactor[0][2] =      TwobyTwodeterminant(A[1][0], A[1][1], A[2][0], A[2][1]);
    cofactor[1][0] = -1 * TwobyTwodeterminant(A[0][1], A[0][2], A[2][1], A[2][2]);
    cofactor[1][1] =      TwobyTwodeterminant(A[0][0], A[0][2], A[2][0], A[2][2]);
    cofactor[1][2] = -1 * TwobyTwodeterminant(A[0][0], A[0][1], A[2][0], A[2][1]);
    cofactor[2][0] =      TwobyTwodeterminant(A[0][1], A[0][2], A[1][1], A[1][2]);
    cofactor[2][1] = -1 * TwobyTwodeterminant(A[0][0], A[0][2], A[1][0], A[1][2]);
    cofactor[2][2] =      TwobyTwodeterminant(A[0][0], A[0][1], A[1][0], A[1][1]);

    cout << " The co factor matrix is {" << endl;
    DisplayMatrix(cofactor, 3, 3);

    //Transpose the cofactor matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //Swap columns of cofactors with rows in the traspose
            cofactor_transposed[i][j] = cofactor[j][i];
        }
    }

    cout << " The co factor matrix transposed is " << endl;
    DisplayMatrix(cofactor_transposed, 3, 3);

    //Divide each adjoint element by the determinant of A
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempmatrix[i][j] = cofactor_transposed[i][j] / ThreebyThreedeterminant(A);
            cout << tempmatrix[i][j] << " = " << cofactor_transposed[i][j] << " / " << ThreebyThreedeterminant(A) << endl;;
        }
    }

    //Assign values to inverse matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            A_minus_1[i][j] = tempmatrix[i][j];
        }
    }
    DisplayMatrix(A_minus_1, 3, 3);
    return A_minus_1;
}

double* Mutiply(double** matrix, double* vector1, double* vector2, int rows, int columns, int vector_size)
{
    rows, columns = 3;
    
    cout << "Matrix x Vector " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            vector2[i] += matrix[i][j] * vector1[j];
        }
    }

    DisplayVector(vector2, 3);

    return vector2;
}

int main()
{
    cout << "This script will solve a system of linear equations in matrix form " << endl;
    double** A = MakeMatrix(3);
    EnterMatrixElements(A, 3);

    double* b = MakeVector(3);
    EnterVectorElements(b);
    double* c = MakeVector(3);
    MakeDummyVector(c);

    cout << ThreebyThreedeterminant(A);

    double** A_Minus_1 = MakeMatrix(3);
    A_Minus_1 = InverseA(A);
    Mutiply(A_Minus_1, b, c, 3, 3, 3);

    DeleteMatrix(A, 3);
    DeleteVector(b);
    DeleteVector(c);
    return 0;
}