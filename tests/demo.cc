#include "gtest/gtest.h"

namespace alltest {

TEST(Demo, Work) {
  int a = 1;
  int b = 2;
  ASSERT_EQ(a + b, 3);

} // namespace learn_cpp

} // namespace alltest