#pragma once

#include <set>
#include <string>
#include <unordered_map>
#include <utility>

namespace function {
class var_t {
public:
  using Set = std::set<var_t>;
  using Pair = std::pair<var_t, double>;
  using Map = std::unordered_map<var_t, double>;

  var_t(std::string name) : name_(std::move(name)) {}

  inline bool operator==(var_t const &other) const {
    return name_ == other.name_;
  }

  inline bool operator<(var_t const &other) const {
    return name_ < other.name_;
  }

  inline std::string str() const { return name_; }

private:
  std::string name_;
};
} // namespace function

namespace std {
template <> struct hash<function::var_t> {
  std::size_t operator()(function::var_t const &v) const noexcept {
    return std::hash<std::string>()(v.str());
  }
};
} // namespace std