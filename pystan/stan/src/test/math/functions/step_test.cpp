#include "stan/math/functions/step.hpp"
#include <gtest/gtest.h>

TEST(MathFunctions, step_double) {
  using stan::math::step;
  
  EXPECT_EQ(1, step(3.7));
  EXPECT_EQ(1, step(0.0));
  EXPECT_EQ(0, step(-2.93));
}

TEST(MathFunctions, step_int) {
  using stan::math::step;

  EXPECT_EQ(1, step(int(4)));
  EXPECT_EQ(1, step(int(0)));
  EXPECT_EQ(0, step(int(-3)));
}
