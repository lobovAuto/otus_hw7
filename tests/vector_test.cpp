#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "vector.hpp"
#include <iostream>

struct Vector_fixture : public testing::Test {
    Vector<unsigned int> test_vector;
    Vector<unsigned int> ref_vector;
    void SetUp() override {
        for (unsigned int i=0; i<2; i++){
            test_vector.push_back(i);
        }
    }
    void TearDown () override {

    }
};

template <typename T> bool cont_comparison(Container<T> & a, Container<T> & b){
    if (a.size()!=b.size()){return false;}
    for (unsigned int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){return false;}
    }
    return true;
}

template <typename T> void print_info(Container<T> & con, std::string name){
    std::cout<<name<<" size is "<<con.size()<<std::endl;
    for (unsigned int i=0; i<con.size(); i++) {
        std::cout<<con[i]<<" ";
    }
    std::cout<<std::endl;
}

    // print_info(test_vector, "test");
    // print_info(ref_vector, "ref");

TEST_F (Vector_fixture, ins_top){
    //Arrange
    ref_vector.push_back(10);
    ref_vector.push_back(0);
    ref_vector.push_back(1);
    //Act
    test_vector.insert(10,0);
    //Assert

    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, ins_mid){
    //Arrange
    ref_vector.push_back(0);
    ref_vector.push_back(20);
    ref_vector.push_back(1);
    //Act
    test_vector.insert(20,1);
    //Assert

    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, ins_bot){
    //Arrange
    ref_vector.push_back(0);
    ref_vector.push_back(1);
    ref_vector.push_back(30);
    //Act
    test_vector.insert(30,2);
    //Assert
    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, er_top){
    //Arrange
    ref_vector.push_back(1);
    //Act
    test_vector.erase(0);
    //Assert
    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, er_mid){
     //Arrange
    ref_vector.push_back(0);
    ref_vector.push_back(2);
    test_vector.push_back(2);
    //Act
    test_vector.erase(1);
    //Assert
    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, er_bot){
    //Arrange
    ref_vector.push_back(0);
    //Act
    test_vector.erase(1);
    //Assert
    EXPECT_TRUE(cont_comparison(test_vector, ref_vector));
}

TEST_F (Vector_fixture, check_size){
    //Arrange

    //Act
    
    //Assert
    EXPECT_EQ(test_vector.size(),2);
}

TEST_F (Vector_fixture, get_cell_val){
    //Arrange

    //Act
    
    //Assert
    EXPECT_EQ(test_vector[1],1);
}

TEST_F (Vector_fixture, oversize_insert){
    //Arrange

    //Act
    try {test_vector.insert(30,5);}
    catch (...) {}
    //Assert
    EXPECT_TRUE(true);
}

TEST_F (Vector_fixture, empty_erase){
    //Arrange
    Vector<unsigned int> test_vector_2;
    //Act
    try {test_vector_2.erase(0);}
    catch (...) {}
    //Assert
    EXPECT_TRUE(true);
}