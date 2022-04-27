#include<iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Matrix.hpp"
const int DOUBLE_SIZE = 8;

namespace zich{
    //Constructors
    Matrix::Matrix(){
        std::vector<double> vec = {0};
        this->_col = 1;
        this->_row = 1;
        this->_mat = vec;
        this->_size = 1;
    }
    Matrix::Matrix(const std::vector<double> &m, int r, int c){
        if(r < 1 || c < 1){
            throw std::runtime_error("Matrix Constructor Error: Row must be greater than 0.");
        }
        if(r*c != m.size()){
            throw std::runtime_error("Matrix Constructor Error: Vector size does not match row*column input.");
        }
        if(m.empty()){
            throw std::runtime_error("Matrix Constructor Error: Vector is empty.");
        }
        for(int i=0; i<(m.size()); i++){
            if(sizeof(m.at(i)) != DOUBLE_SIZE){
                throw std::runtime_error("Matrix Constructor Error: Vector element is not of type double.");
            }
        }
        this->_row = r;
        this->_col = c;
        this->_size = r*c;
        this->setVector(m);
    }
    Matrix::Matrix(const Matrix& other){
        this->_col = other.getColumn();
        this->_row = other.getRow();
        this->_size = other.getSize();
        this->_mat = other.getVector();
    }

    //Destructor
    Matrix::~Matrix(){};


    //Operator (+):
    Matrix Matrix::operator + (const Matrix& other) const{return other;}

    //Operator (-):
    Matrix Matrix::operator - (const Matrix& other) const{return other;}

    //Operator (mat*mat):
    Matrix Matrix::operator * (const Matrix& other) const{return other;}

    //Operator (mat*num):
    Matrix Matrix::operator * (const double scalar) const{return *this;}

    //Operator (num*mat)):
    Matrix operator * (double num, const Matrix& other){return other;}
    
    //Operator (+=):
    Matrix& Matrix::operator += (const Matrix& other){return *this;}

    //Operator (-=):
    Matrix& Matrix::operator -= (const Matrix& other){return *this;}

    //Operator (*=):
    Matrix& Matrix::operator *= (const Matrix& other){return *this;}

    //Operator (*= num):
    Matrix& Matrix::operator *= (const double num){return *this;}

    //Operator (==):
    bool Matrix::operator == (const Matrix& other) const{return true;}

    //Operator (!=):
    bool Matrix::operator != (const Matrix& other) const{return true;}

    //Operator (>=):
    bool Matrix::operator >= (const Matrix& other) const{return true;}

    //Operator (<=):
    bool Matrix::operator <= (const Matrix& other) const{return true;}

    //Operator (>):
    bool Matrix::operator > (const Matrix& other) const{return true;}

    //Operator (<):
    bool Matrix::operator < (const Matrix& other) const{return true;}

    //Operator (++prefix):
    Matrix& Matrix::operator ++ (){return *this;}

    //Operator (--prefix):
    Matrix& Matrix::operator -- (){return *this;}

    //Operator (- prefix):
    Matrix& Matrix::operator - (){return *this;
}
    //Operator (+ prefix):
    Matrix& Matrix::operator + (){return *this;}

    //Operator (postfix++)):
    Matrix Matrix::operator ++ (int) {return *this;}

     //Operator (postfix--)):
    Matrix Matrix::operator -- (int) {return *this;}

    //Operator (cout)):
    std::ostream& operator << (std::ostream& out, const Matrix& other){return out;}
    
    //Operator (cin)):
    std::istream& operator >> (std::istream& in,  Matrix& other){return in;}

//     //Assignment Operators:
//     void Matrix::operator += (const Matrix& other){}
//     void Matrix::operator -= (const Matrix& other){}
//     void Matrix::operator *= (double num){}

//     //Unary Operators:
//     Matrix Matrix::operator ++ (){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     }
//     Matrix Matrix::operator -- (){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     } 
//     Matrix Matrix::operator ++ (int){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     } 
//     Matrix Matrix::operator -- (int){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     } 
//     Matrix Matrix::operator + (){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     } 
//     Matrix Matrix::operator - (){
//         Matrix stam{this->getVector(), this->getRow(), this->getColumn()};
//         return stam;
//     } 
//     //Relational Operators (boolean):
//     bool Matrix::operator > (const Matrix& other){
//         return true;
//     }
//     bool Matrix::operator < (const Matrix& other){
//         return true;
//     }
//     bool Matrix::operator >= (const Matrix& other){
//         return true;
//     }
//     bool Matrix::operator <= (const Matrix& other){
//         return true;
//     }
//     bool Matrix::operator == (const Matrix& other){
//         return true;
//     }
//     bool Matrix::operator != (const Matrix& other){
//         return true;
//     }

//     //io Operators:
//     std::ostream& operator << (std::ostream& outStream, const Matrix&  mat){
        
//         return outStream;
//     }
//     std::istream& operator >> (std::istream& inStream, const Matrix& mat){
//         return inStream;
//     }

// }
}