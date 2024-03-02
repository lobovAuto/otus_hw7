#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "list.hpp"
#include <iostream>

struct List_fixture : public testing::Test {
    List<unsigned int> test_list;
    List<unsigned int> ref_list;
    void SetUp() override {
        for (unsigned int i=0; i<2; i++){
            test_list.push_back(i);
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

    // print_info(test_list, "test");
    // print_info(ref_list, "ref");

TEST_F (List_fixture, ins_top){
    //Arrange
    ref_list.push_back(10);
    ref_list.push_back((unsigned int)0);
    ref_list.push_back(1);
    //Act
    test_list.insert(10,0);
    //Assert

    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, ins_mid){
    //Arrange
    ref_list.push_back((unsigned int)0);
    ref_list.push_back(20);
    ref_list.push_back(1);
    //Act
    test_list.insert(20,1);
    //Assert

    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, DISABLED_ins_bot){
    //Arrange
    ref_list.push_back((unsigned int)0);
    ref_list.push_back(1);
    ref_list.push_back(30);
    //Act
    test_list.insert(30,3);
    //Assert
    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, er_top){
    //Arrange
    ref_list.push_back(1);
    //Act
    test_list.erase(0);
    //Assert
    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, er_mid){
     //Arrange
    ref_list.push_back((unsigned int)0);
    ref_list.push_back(2);
    test_list.push_back(2);
    //Act
    test_list.erase(1);
    //Assert
    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, er_bot){
    //Arrange
    ref_list.push_back((unsigned int)0);
    //Act
    std::cout<<test_list.size()<<std::endl;
    test_list.erase(1);
    //Assert
    EXPECT_TRUE(cont_comparison(test_list, ref_list));
}

TEST_F (List_fixture, check_size){
    //Arrange

    //Act
    
    //Assert
    EXPECT_EQ(test_list.size(),2);
}

TEST_F (List_fixture, get_cell_val){
    //Arrange

    //Act
    
    //Assert
    EXPECT_EQ(test_list[1],1);
}