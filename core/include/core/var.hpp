#pragma once

#include <core/const.hpp>
#include <core/function.hpp>
#include <core/var_t.hpp>

#include <cassert>

namespace function {
class Var : public Function {
public:
  explicit Var(var_t v) : v_(std::move(v)) {}
  inline static Function::UPtr make(var_t v) {
    return std::make_unique<Var>(std::move(v));
  }
  inline double operator()(var_t::Map const &map) const override {
    const auto itr = map.find(v_);
    assert(itr != map.end());
    return (*itr).second;
  }
  inline virtual std::string str() const override { return v_.str(); }
  inline virtual Function::UPtr derivative(var_t::Set const &vs,
                                           size_t n = 1) const {
    if (n == 0)
      return clone();
    if (vs.count(v_))
      return Const::make(1.0);
    return Const::make(0.0);
  }

  inline virtual Function::UPtr clone() const override {
    return std::make_unique<Var>(*this);
  }
  inline virtual var_t::Set vars() const override { return var_t::Set({v_}); }
  virtual ~Var() override = default;

private:
  var_t v_;
};
} // namespace function