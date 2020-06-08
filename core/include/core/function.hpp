#pragma once

#include <core/var_t.hpp>

#include <concepts>
#include <memory>
#include <string>

namespace function {
class Function {
public:
  using Ptr = std::shared_ptr<Function>;
  using UPtr = std::unique_ptr<Function>;

  virtual double operator()(var_t::Map const &map) const = 0;
  virtual std::string str() const = 0;
  virtual UPtr derivative(var_t::Set const &vs, size_t n) const = 0;
  virtual UPtr clone() const = 0;
  virtual var_t::Set vars() const = 0;
  virtual ~Function() = default;
};
} // namespace function