#include <core/const.hpp>
#include <core/var_t.hpp>

#include <gtest/gtest.h>

#include <string>

namespace function {
TEST(ConstTest, Str) {
  const auto x = 1.0;
  const auto x_str = std::to_string(x);
  const auto x_const = Const::make(x);

  EXPECT_EQ(x_const->str(), x_str);
}

TEST(ConstTest, Call) {
  const auto x = 1.0;
  const auto x_const = Const::make(x);

  EXPECT_DOUBLE_EQ((*x_const)(var_t::Map({})), x);
}

TEST(ConstTest, Derivative) {
  const auto x = 1.0;
  const auto x_const = Const::make(x);
  const auto v = var_t("x");
  const auto m = var_t::Map({var_t::Pair(v, 10.0)});

  const auto x_const_0 = x_const->derivative({v}, 0);
  const auto x_const_1 = x_const->derivative({v}, 1);

  EXPECT_DOUBLE_EQ((*x_const_0)(m), x);
  EXPECT_DOUBLE_EQ((*x_const_1)(m), 0.0);
}

TEST(ConstTest, Vars) {
  const auto x = 1.0;
  const auto x_const = Const::make(x);

  const auto vs = x_const->vars();
  EXPECT_EQ(vs.size(), 0);
}
} // namespace function

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}