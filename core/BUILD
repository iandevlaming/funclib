load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

package(default_visibility = ["//visibility:public"])

# libraries

cc_library(
    name = "const",
    hdrs = ["include/core/const.hpp"],
    strip_include_prefix = "include",
    deps = [
        ":function",
        ":var_t",
    ],
)

cc_library(
    name = "function",
    hdrs = ["include/core/function.hpp"],
    strip_include_prefix = "include",
    deps = [":var_t"],
)

cc_library(
    name = "var",
    hdrs = ["include/core/var.hpp"],
    strip_include_prefix = "include",
    deps = [
        ":const",
        ":function",
        ":var_t",
    ],
)

cc_library(
    name = "var_t",
    hdrs = ["include/core/var_t.hpp"],
    strip_include_prefix = "include",
)

#tests

cc_test(
    name = "const_test",
    srcs = ["test/const_test.cpp"],
    deps = [
        ":const",
        "@com_google_googletest//:gtest",
    ],
)

cc_test(
    name = "var_test",
    srcs = ["test/var_test.cpp"],
    deps = [
        ":var",
        "@com_google_googletest//:gtest",
    ],
)

cc_test(
    name = "var_t_test",
    srcs = ["test/var_t_test.cpp"],
    deps = [
        ":var_t",
        "@com_google_googletest//:gtest",
    ],
)
