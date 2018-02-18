//
// Created by Sofia Migliorini on 07/02/18.
//

#include "gtest/gtest.h"
#include "../MatrixTemplate.h"

class MatrixTemplateFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        matrixInt = new MatrixTemplate<int> (2,2);
        matrixInt1 = new MatrixTemplate<int> (2,2);
        matrixInt2 = new MatrixTemplate<int> (3,2);
        matrixInt3 = new MatrixTemplate<int> (3,3);
        matrixInt->setValue(3, 0, 0);
        matrixInt->setValue(2, 0, 1);
        matrixInt->setValue(7, 1, 0);
        matrixInt->setValue(5, 1, 1);
        matrixInt1->setValue(2, 0, 0);
        matrixInt1->setValue(3, 0, 1);
        matrixInt1->setValue(1, 1, 0);
        matrixInt1->setValue(4, 1, 1);
        matrixInt2->setValue(2, 0, 0);
        matrixInt2->setValue(1, 0, 1);
        matrixInt2->setValue(0, 1, 0);
        matrixInt2->setValue(3, 1, 1);
        matrixInt2->setValue(1, 2, 0);
        matrixInt2->setValue(1, 2, 1);
        matrixInt3->setValue(2, 0, 0);
        matrixInt3->setValue(1, 0, 1);
        matrixInt3->setValue(1, 0, 2);
        matrixInt3->setValue(3, 2, 0);
        matrixInt3->setValue(4, 2, 1);
        matrixInt3->setValue(1, 2, 2);
    }

    MatrixTemplate<int> *matrixInt;
    MatrixTemplate<int> *matrixInt1;
    MatrixTemplate<int> *matrixInt2;
    MatrixTemplate<int> *matrixInt3;
};


TEST_F(MatrixTemplateFixture, TestGetRow) {
    EXPECT_EQ(3, (matrixInt->getRow(0))[0]);
    EXPECT_EQ(2, (matrixInt->getRow(0))[1]);
    EXPECT_EQ(7, (matrixInt->getRow(1))[0]);
    EXPECT_EQ(5, (matrixInt->getRow(1))[1]);
}


TEST_F(MatrixTemplateFixture, TestFalseGetRow) {
    ASSERT_THROW(matrixInt->getRow(2), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestGetColumn) {
    EXPECT_EQ(3, (matrixInt->getColumn(0))[0]);
    EXPECT_EQ(7, (matrixInt->getColumn(0))[1]);
    EXPECT_EQ(2, (matrixInt->getColumn(1))[0]);
    EXPECT_EQ(5, (matrixInt->getColumn(1))[1]);
}

TEST_F(MatrixTemplateFixture, TestFalseGetColumn) {
    ASSERT_THROW(matrixInt->getColumn(3), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestTranspose) {
    EXPECT_EQ(3, (matrixInt->transpose())[0]);
    EXPECT_EQ(7, (matrixInt->transpose())[1]);
    EXPECT_EQ(2, (matrixInt->transpose())[2]);
    EXPECT_EQ(5, (matrixInt->transpose())[3]);
}

TEST_F(MatrixTemplateFixture, TestDeterminant) {
    EXPECT_EQ(1, matrixInt->determinant(matrixInt));
    EXPECT_EQ(5, matrixInt1->determinant(matrixInt1));
    EXPECT_EQ(0, matrixInt3->determinant(matrixInt3));
}

TEST_F(MatrixTemplateFixture, TestFalseDeterminant) {
    ASSERT_THROW(matrixInt2->determinant(matrixInt2), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestInverse) {
    EXPECT_EQ(5, (matrixInt->inverse())[0]);
    EXPECT_EQ(-2, (matrixInt->inverse())[1]);
    EXPECT_EQ(-7, (matrixInt->inverse())[2]);
    EXPECT_EQ(3, (matrixInt->inverse())[3]);
}

TEST_F(MatrixTemplateFixture, TestFalseInverse) {
    EXPECT_THROW(matrixInt2->inverse(), std::runtime_error);
    EXPECT_THROW(matrixInt3->inverse(), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestSum) {
    EXPECT_EQ(5, (matrixInt->sum(matrixInt1))[0]);
    EXPECT_EQ(5, (matrixInt->sum(matrixInt1))[1]);
    EXPECT_EQ(8, (matrixInt->sum(matrixInt1))[2]);
    EXPECT_EQ(9, (matrixInt->sum(matrixInt1))[3]);
}

TEST_F(MatrixTemplateFixture, TestFalseSum) {
    ASSERT_THROW(matrixInt->sum(matrixInt2), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestSub) {
    EXPECT_EQ(1, (matrixInt->sub(matrixInt1))[0]);
    EXPECT_EQ(-1, (matrixInt->sub(matrixInt1))[1]);
    EXPECT_EQ(6, (matrixInt->sub(matrixInt1))[2]);
    EXPECT_EQ(1, (matrixInt->sub(matrixInt1))[3]);
}

TEST_F(MatrixTemplateFixture, TestFalseSub) {
    ASSERT_THROW(matrixInt->sub(matrixInt2), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestMul) {
    EXPECT_EQ(8, (matrixInt->mul(matrixInt1))[0]);
    EXPECT_EQ(17, (matrixInt->mul(matrixInt1))[1]);
    EXPECT_EQ(19, (matrixInt->mul(matrixInt1))[2]);
    EXPECT_EQ(41, (matrixInt->mul(matrixInt1))[3]);
}

TEST_F(MatrixTemplateFixture, TestFalseMul) {
    ASSERT_THROW(matrixInt->mul(matrixInt2), std::runtime_error);
}

TEST_F(MatrixTemplateFixture, TestEq) {
    EXPECT_TRUE(matrixInt == matrixInt);
    EXPECT_FALSE(matrixInt == matrixInt1);
}

TEST_F(MatrixTemplateFixture, TestAssig) {
    matrixInt = matrixInt1;
    EXPECT_EQ(2, matrixInt->getValue(0, 0));
    EXPECT_EQ(3, matrixInt->getValue(0, 1));
    EXPECT_EQ(1, matrixInt->getValue(1, 0));
    EXPECT_EQ(4, matrixInt->getValue(1, 1));
}


