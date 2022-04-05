#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm> //for copy() (setter)
#include <iterator> //for back_inserter (setter)

namespace zich{
    class Matrix{
    
        //Variables of class are private in default.
        std::vector<double> mat;
         int row, column;

        public:
        //Constructor:
        Matrix(const std::vector<double> m,  const int r,  const int c);
        // //Destructor
        ~Matrix();

        //Getters:
        //Adding 'const' to make sure the getter doesn't allow the variables to be changed.
         int getRow() const{
            return row;
        }
         int getColumn() const{
            return column;
        }
        std::vector<double> getVector() const{
            return mat;
        }
        //Setters:
        void setRow( int r){
            this->row = r;
        }
        void setColumn( int c){
            this->column = c;
        }
        void setVector(std::vector<double> other){
            copy(other.begin(), other.end(), back_inserter(this->mat));
        }


        //Arithmetic Operators: 
        Matrix operator + (const Matrix& other); //adding to matrixs together (returns new Matrix)
        Matrix operator - (const Matrix& other); //subtracting to matrixs together (returns new Matrix)
        Matrix &operator * (double scalar); //multiplying the base matrix be double (return new Matrix)
        friend Matrix operator * (double scalar, const Matrix& other); //multiplying two matrixs (return new Matrix)
        

        //Assignment Operators:
        void operator += (const Matrix& other); //adding a matrix to a base matrix
        void operator -= (const Matrix& other); //subtracting a matrix to a base matrix
        void operator *= (double num); // multiplying by a double

        //Unary Operators:
        Matrix operator ++ (); //increment the matrix (++prefix)
        Matrix operator -- (); //decrement the matrix (--prefix)
        Matrix operator ++ (int); //increment the matrix by (postfix++)
        Matrix operator -- (int); //increment the matrix by (postfix--)
        Matrix operator + (); //changes the vlaues of the matrix to positive
        Matrix operator - (); //changes the vlaues of the matrix to negative

        //Relational Operators (boolean):
        bool operator > (const Matrix& other);
        bool operator < (const Matrix& other);
        bool operator >= (const Matrix& other);
        bool operator <= (const Matrix& other);
        bool operator == (const Matrix& other);
        bool operator != (const Matrix& other);

        //io Operators:
        friend std::ostream& operator << (std::ostream& outStream, const Matrix&  mat); //for overriding cout
        friend std::istream& operator >> (std::istream& inStream, const Matrix& mat); //for overriding cin
    };
}


