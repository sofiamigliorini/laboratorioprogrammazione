cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp MatrixTemplateFixture.cpp MatrixTemplateTest.cpp)
add_executable(runMatrixTests ${TEST_SOURCE_FILES})
target_link_libraries(runMatrixTests gtest gtest_main)

