#include "Matrix.hpp"
#include "doctest.h"

TEST_CASE("Bad Input"){ // 6 tests
    std::vector<double> vec = {0};
    CHECK_THROWS(zich::Matrix(vec, 0, 0)); //both==0
    CHECK_THROWS(zich::Matrix(vec, 0, 1)); //row==0
    CHECK_THROWS(zich::Matrix(vec, 1, 0)); //column==0
    CHECK_THROWS(zich::Matrix(vec, 1, -1)); //column==negative
    CHECK_THROWS(zich::Matrix(vec, -1, 1)); //row==negative
    CHECK_THROWS(zich::Matrix(vec,-1, -1)); //both==negative
}

TEST_CASE("Bad Arithmetic Operators:"){ // 6 tests
    const std::vector<double> vec = {1,1,1,1,1,1}; //6 indexes
    zich::Matrix test1{vec, 2,3}; //row=2,col=3
    zich::Matrix test2{vec, 3,2}; //row=3,col=2
    zich::Matrix test3{vec, 3,2}; //row=3,col=2

    CHECK_THROWS(test1 + test2); //dimensions don't equal (+)
    CHECK_THROWS(test1 - test2); //dimensions don't equal (-)
    
    
    CHECK((test1 + test2).getVector().at(0) == 2); //valid answer (+)
    CHECK((test1 - test2).getVector().at(0) == 0); //valid answer (-)
    
    CHECK((test1*5).getVector().at(0) == 5); //valid answer (* by scalar postfix)
    CHECK((5*test1).getVector().at(0) == 5); //valid answer (* by scalar prefix)
}

TEST_CASE("Assignment Operators:"){ //6 tests
    const std::vector<double> v = {2,2,2,2,2,2}; //6 indexes
    const std::vector<double> x = {-1,2,2,2,2,2}; //6 indexes

    zich::Matrix test2{v, 3,2}; //row=3,col=2
    zich::Matrix test3{v, 3,2}; //row=3,col=2


    
    CHECK_THROWS((test2 += test3)); //dimensions don't equal (+=)
    CHECK_THROWS((test2 -= test3)); //dimensions don't equal (-=)
    
    CHECK_NOTHROW((test2 += test2)); //check compile (+=)
    CHECK_NOTHROW((test3 -= test3)); //check compile (-=)

    zich::Matrix test4{x, 3,2}; //row=3,col=2
    test4 += test4;
    CHECK(test4.getVector().at(0) == -2); //check answer (+=)
    
    zich::Matrix test5{x, 3,2}; //row=3,col=2
    test5 -= test5;
    CHECK(test5.getVector().at(0) == 0); //check answer (+=)
}


TEST_CASE("Unary Operators:"){ //10 tests
    const std::vector<double> v = {1,1,1,1,1,1}; //6 indexes
    
    zich::Matrix test1{v, 2,3}; //row=2,col=3
    zich::Matrix test2{v, 2,3}; //row=2,col=3

    CHECK_NOTHROW(test1++); //check prefix++
    CHECK_NOTHROW(++test1); //check ++prefix
    CHECK_NOTHROW(test1--);//check prefix--
    CHECK_NOTHROW(--test1);//check --prefix
    CHECK_NOTHROW(+(test1));//check --prefix
    CHECK_NOTHROW(-(test1));//check --prefix

    test1++;
    CHECK(test1.getVector().at(0) == 2);
    ++test1;
    CHECK(test1.getVector().at(0) == 3);
    test1--;
    CHECK(test1.getVector().at(0) == 2);
    --test1;
    CHECK(test1.getVector().at(0) == 1);
}

TEST_CASE("Relational Operators (boolean):"){
    const std::vector<double> v = {1,1,1,1,1,1}; //6 indexes
    const std::vector<double> v2 = {5,5,5,5,5,5}; //6 indexes
    zich::Matrix test1{v, 2,3}; //row=2,col=3
    zich::Matrix test2{v, 2,3}; //row=2,col=3
    zich::Matrix test3{v, 2,3}; //row=2,col=3
    zich::Matrix test4{v, 6,1}; //row=6,col=1

    
    CHECK((test1 > test2) == false);
    CHECK((test2 > test1) == true);

    CHECK((test1 >= test2) == false);
    CHECK((test2 <= test1) == false);
    CHECK((test1 <= test1) == true);
    CHECK((test2 >= test3) == true);

    CHECK((test1 == test2) == false);
    CHECK((test1 == test1) == true);
    CHECK((test2 == test3) == true);

    CHECK((test1 != test1) == false);
}