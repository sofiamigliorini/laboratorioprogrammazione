//
// Created by Sofia Migliorini on 07/02/18.
//

#include "gtest/gtest.h"
#include "../MatrixTemplate.h"

TEST(MatrixTemplate, DefaultConstructor) {
    MatrixTemplate<int> matrixInt;
    ASSERT_EQ(2, matrixInt.getRows());
    ASSERT_EQ(2, matrixInt.getColumns());
    ASSERT_EQ(0, matrixInt.getValue(0, 0));
    ASSERT_EQ(0, matrixInt.getValue(0, 1));
    ASSERT_EQ(0, matrixInt.getValue(1, 0));
    ASSERT_EQ(0, matrixInt.getValue(1, 1));
}
