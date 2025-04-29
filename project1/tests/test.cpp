#include <gtest/gtest.h>

// A simple function to test
int add(int a, int b) {
    return a + b;
}

TEST(MathTest, Addition) {
  EXPECT_EQ(add(3, 4), 7);
}