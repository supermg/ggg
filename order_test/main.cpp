#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);// ---------->初始化GTEST
  return RUN_ALL_TESTS();                 //  ---------->执行测试，并给出结果
}