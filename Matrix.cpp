#include<iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"


namespace zich{
    //Constructor:
    Matrix::Matrix(const std::vector<double> m, const int r, const int c){
        this->setColumn(c);
        this->setRow(r);
        this->setVector(m);
    }
    Matrix::~Matrix(){}

    //Arithmetic Operators: 
    Matrix Matrix::operator + (const Matrix& other){
        return other;
    }

    Matrix Matrix::operator - (const Matrix& other){
        return other;
    }

    Matrix& Matrix::operator * (double scalar){
        return *this;
    }

    Matrix operator * (double scalar, const Matrix& other){
        return other;
    }
    
    

    //Assignment Operators:
    void Matrix::operator += (const Matrix& other){}
    void Matrix::operator -= (const Matrix& other){}
    void Matrix::operator *= (double num){}

    //Unary Operators:
    Matrix Matrix::operator ++ (){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    }
    Matrix Matrix::operator -- (){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    } 
    Matrix Matrix::operator ++ (int){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    } 
    Matrix Matrix::operator -- (int){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    } 
    Matrix Matrix::operator + (){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    } 
    Matrix Matrix::operator - (){
        Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
        return stam;
    } 
    //Relational Operators (boolean):
    bool Matrix::operator > (const Matrix& other){
        return true;
    }
    bool Matrix::operator < (const Matrix& other){
        return true;
    }
    bool Matrix::operator >= (const Matrix& other){
        return true;
    }
    bool Matrix::operator <= (const Matrix& other){
        return true;
    }
    bool Matrix::operator == (const Matrix& other){
        return true;
    }
    bool Matrix::operator != (const Matrix& other){
        return true;
    }

    //io Operators:
    std::ostream& operator << (std::ostream& outStream, const Matrix&  mat){
        
        return outStream;
    }
    std::istream& operator >> (std::istream& inStream, const Matrix& mat){
        return inStream;
    }

}
    