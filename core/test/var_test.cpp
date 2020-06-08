
#include <core/var.hpp>

#include <gtest/gtest.h>

#include <string>

namespace function {
TEST(VarTest, Str) {
  const auto v_str = std::string("x");
  const auto v = var_t("x");
  const auto var = Var::make(v);

  EXPECT_EQ(var->str(), v_str);
}

TEST(VarTest, Call) {
  const auto v_str = std::string("x");
  const auto v = var_t(v_str);
  const auto var = Var::make(v);

  const auto x = 1.0;
  const auto m = var_t::Map({var_t::Pair(v, x)});
  EXPECT_DOUBLE_EQ((*var)(m), x);
}

TEST(VarTest, Derivative) {
  const auto v_str_x = std::string("x");
  const auto v_str_y = std::string("y");
  const auto v_x = var_t(v_str_x);
  const auto v_y = var_t(v_str_y);
  const auto var = Var::make(v_x);

  const auto dvar_x_0 = var->derivative({v_x}, 0);
  EXPECT_EQ(dvar_x_0->str(), v_str_x);

  const auto dvar_y_0 = var->derivative({v_y}, 0);
  EXPECT_EQ(dvar_y_0->str(), v_str_x);

  const auto dvar_x_1 = var->derivative({v_x}, 1);
  EXPECT_EQ(dvar_x_1->str(),
            std::to_string(1.0)); // this is bad, really need a way to get
                                  // derived type from base (registry? CRTP?)

  const auto dvar_y_1 = var->derivative({v_y}, 1);
  EXPECT_EQ(dvar_y_1->str(), std::to_string(0.0));

  const auto dvar_xy_1 = var->derivative({v_x, v_y}, 1);
  EXPECT_EQ(dvar_xy_1->str(), std::to_string(1.0));
}

TEST(VarTest, Vars) {
  const auto v_str = std::string("x");
  const auto v = var_t(v_str);
  const auto var = Var::make(v);

  const auto vs = var->vars();
  EXPECT_EQ(vs.size(), 1);
  EXPECT_TRUE(vs.count(v));
}
} // namespace function

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}