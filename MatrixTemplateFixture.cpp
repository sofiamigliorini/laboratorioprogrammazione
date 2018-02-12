//
// Created by Sofia Migliorini on 07/02/18.
//

#include "gtest/gtest.h"
#include "../MatrixTemplate.h"

class MatrixTemplateFixture : public ::testing::Test {


protected:
    virtual void SetUp() override {
        matrixInt.setValue(3, 0, 0);
        matrixInt.setValue(2, 0, 1);
        matrixInt.setValue(7, 1, 0);
        matrixInt.setValue(5, 1, 1);
        matrixInt1.setValue(2, 0, 0);
        matrixInt1.setValue(3,0,1);
        matrixInt1.setValue(1,1,0);
        matrixInt1.setValue(4,1,1);
    }

    MatrixTemplate<int> matrixInt;
    MatrixTemplate<int> matrixInt1;
};


TEST_F(MatrixTemplateFixture, TestGetRow) {
    EXPECT_EQ(3, matrixInt.getRow(0).getValue(0,0));
    EXPECT_EQ(2, matrixInt.getRow(0).getValue(0,1));
    EXPECT_EQ(7, matrixInt.getRow(1).getValue(0,0));
    EXPECT_EQ(5, matrixInt.getRow(1).getValue(0,1));
}

TEST_F(MatrixTemplateFixture, TestGetColumn) {
    EXPECT_EQ(3, matrixInt.getColumn(0).getValue(0,0));
    EXPECT_EQ(7, matrixInt.getColumn(0).getValue(1,0));
    EXPECT_EQ(2, matrixInt.getColumn(1).getValue(0,0));
    EXPECT_EQ(5, matrixInt.getColumn(1).getValue(1,0));
}

TEST_F(MatrixTemplateFixture, TestTranspose){
    EXPECT_EQ(3, matrixInt.transpose().getValue(0,0));
    EXPECT_EQ(7, matrixInt.transpose().getValue(0,1));
    EXPECT_EQ(2, matrixInt.transpose().getValue(1,0));
    EXPECT_EQ(5, matrixInt.transpose().getValue(1,1));
}

TEST_F(MatrixTemplateFixture, TestDeterminant){
    EXPECT_EQ(1, matrixInt.determinant(matrixInt));
    EXPECT_EQ(5, matrixInt1.determinant(matrixInt1));
}

TEST_F(MatrixTemplateFixture, TestInverse){
    EXPECT_EQ(5, matrixInt.inverse().getValue(0,0));
    EXPECT_EQ(-2, matrixInt.inverse().getValue(0,1));
    EXPECT_EQ(-7, matrixInt.inverse().getValue(1,0));
    EXPECT_EQ(3, matrixInt.inverse().getValue(1,1));
}

TEST_F(MatrixTemplateFixture, TestSum){
    EXPECT_EQ(5, (matrixInt+matrixInt1).getValue(0,0));
    EXPECT_EQ(5, (matrixInt+matrixInt1).getValue(0,1));
    EXPECT_EQ(8, (matrixInt+matrixInt1).getValue(1,0));
    EXPECT_EQ(9, (matrixInt+matrixInt1).getValue(1,1));
}

TEST_F(MatrixTemplateFixture, TestSub){
    EXPECT_EQ(1, (matrixInt-matrixInt1).getValue(0,0));
    EXPECT_EQ(-1, (matrixInt-matrixInt1).getValue(0,1));
    EXPECT_EQ(6, (matrixInt-matrixInt1).getValue(1,0));
    EXPECT_EQ(1, (matrixInt-matrixInt1).getValue(1,1));
}

TEST_F(MatrixTemplateFixture, TestMul){
    EXPECT_EQ(8, (matrixInt*matrixInt1).getValue(0,0));
    EXPECT_EQ(17, (matrixInt*matrixInt1).getValue(0,1));
    EXPECT_EQ(19, (matrixInt*matrixInt1).getValue(1,0));
    EXPECT_EQ(41, (matrixInt*matrixInt1).getValue(1,1));
}

TEST_F(MatrixTemplateFixture, TestEq){
    EXPECT_TRUE(matrixInt==matrixInt);
    EXPECT_FALSE(matrixInt==matrixInt1);
}


