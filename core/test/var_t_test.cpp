#include <core/var_t.hpp>

#include <gtest/gtest.h>

namespace function {
TEST(Var_tTest, Equality) {
  const auto v1 = var_t("x");
  const auto v2 = var_t("x");

  EXPECT_EQ(v1, v2);
}

TEST(var_tTest, Str) {
  const auto v_str = "x";
  const auto v = var_t(v_str);

  EXPECT_EQ(v.str(), v_str);
}

TEST(var_tTest, Set) {
  const auto v1 = var_t("x");
  const auto v2 = var_t("y");
  const auto v2_copy = v2;

  const auto v_set = var_t::Set({v1, v2, v2_copy});

  EXPECT_EQ(v_set.size(), 2);
  EXPECT_TRUE(v_set.count(v1));
  EXPECT_TRUE(v_set.count(v2));
}
} // namespace function

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}