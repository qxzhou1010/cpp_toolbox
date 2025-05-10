#include "gtest/gtest.h"

namespace alltest {

namespace learn_cpp {

TEST(Demo, Work) {
  int a = 1;
  int b = 2;
  ASSERT_EQ(a + b, 3);
}

class Matrix {
public:
  Matrix() {
    for (int row = 0; row < 4; ++row) {
      for (int col = 0; col < 4; ++col) {
        m_data[row][col] = row * col;
      }
    }
  }

  // 2个参数
  double &operator()(int row, int col) { return m_data[row][col]; }

  // 0个参数，对 m_data 做 reset
  void operator()() {
    for (int row = 0; row < 4; ++row) {
      for (int col = 0; col < 4; ++col) {
        m_data[row][col] = 0.0;
      }
    }
  }

private:
  double m_data[4][4]{};
};

TEST(Chapter21, ParenthesisOverload) {
  Matrix m;

  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      ASSERT_EQ(m(row, col), row * col);
    }
  }

  // rest
  m();

  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      ASSERT_EQ(m(row, col), 0.0);
    }
  }
}

class Accumulator {
public:
  Accumulator(){};
  // 我们可以把 Accumulator acc，当做一个 function 去调用: acc()
  // 并且这个 这个 function 可以 store data,因为本质上是一个 class
  // 这种特殊的 function 就叫做 functor
  int operator()(int i) { return (m_ += i); }

private:
  int m_ = 0;
};

TEST(Chapter21, Functor) {

  Accumulator acc;

  std::cout << acc(10) << "\n";
  std::cout << acc(20) << "\n";
  std::cout << acc(30) << "\n";
}

} // namespace learn_cpp
} // namespace alltest
