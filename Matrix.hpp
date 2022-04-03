#pragma once
#include<iostream>
#include <vector>

namespace zich{
    class Matrix{

    //Variables of class or private in default.
    std::vector<double> mat;
    unsigned int row, column;

    public:
    //Constructor:
    Matrix(const std::vector<double> m, const unsigned int r=1, const unsigned int c=1){
        this->mat = m;
        this->row = r;
        this->column = c;
    }
    //Arithmetic Operators 
    Matrix operator + (Matrix const &other); //adding to matrixs together (returns new Matrix)
    Matrix operator - (Matrix const &other); //subtracting to matrixs together (returns new Matrix)
    Matrix operator * (Matrix const &other) //multiplying two matrixs (return new Matrix)
    Matrix operator * (const double x); //multiplying the base matrix be double (return new Matrix)

    //Assignment Operators:
    void operator += (Matrix cont &other); //adding a matrix to a base matrix
    void operator -= (Matrix cont &other); //subtracting a matrix to a base matrix
    void operator *= (double x); // multiplying by a double
    void operator *= (Matrix cont &other); //multiplying by another matrix

    //Unary Operators:
    Matrix operator ++ (); //increment the matrix (++prefix)
    Matrix operator -- (); //decrement the matrix (--prefix)
    Matrix operator ++ (int); //increment the matrix by (postfix++)
    Matrix operator -- (int); //increment the matrix by (postfix--)
    Matrix operator + (); //changes the vlaues of the matrix to positive
    Matrix operator - (); //changes the vlaues of the matrix to negative

    //Relational Operators (boolean):
    bool operator > (Matrix const &other);
    bool operator < (Matrix const &other);
    bool operator >= (Matrix const &other);
    bool operator <= (Matrix const &other);
    bool operator == (Matrix const &other);
    bool operator != (Matrix const &other);

    //io Operators:
    friend std::ostream& operator << (std::ostream& os, const Matrix& mat); //for overriding cout
    friend std::istream& operator >> (std::istream& is, const Matrix& mat); //for overriding cin
};
}
