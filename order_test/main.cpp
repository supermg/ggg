#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);// ---------->��ʼ��GTEST
  return RUN_ALL_TESTS();                 //  ---------->ִ�в��ԣ����������
}