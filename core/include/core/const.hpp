#pragma once

#include <core/function.hpp>

#include <cassert>

namespace function {
class Const : public Function {
public:
  explicit Const(double c = 0.0) : c_(c) {}
  inline static Function::UPtr make(double c) {
    return std::make_unique<Const>(c);
  }
  inline virtual double operator()(var_t::Map const &) const override {
    return c_;
  }
  inline virtual std::string str() const override { return std::to_string(c_); }
  inline virtual Function::UPtr derivative(var_t::Set const &vs,
                                           size_t n = 1) const {
    assert(!vs.empty());
    auto new_c = 0.0;
    if (n == 0)
      new_c = c_;
    return make(new_c);
  }
  inline virtual Function::UPtr clone() const override {
    return std::make_unique<Const>(*this);
  }
  inline virtual var_t::Set vars() const override { return {}; }
  virtual ~Const() override = default;

private:
  double c_;
};
} // namespace function
