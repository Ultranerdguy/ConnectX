#ifndef _CONNECT_X_TYPES_HPP_
#define _CONNECT_X_TYPES_HPP_

#include <cstdint>
#include <vector>

namespace ConnectX {
  using VectorComponent = std::int64_t; // A position in one dimension of the board
  using Vector = std::vector<VectorComponent>; // An N dimensional position vector

  using SizeComponent = std::uint64_t; // A size on one dimension of the board
  using SizeVector = std::vector<SizeComponent>; // An N dimension size

  using Token = std::uint64_t;
  using TokenBuffer = std::vector<Token>;

  template <typename T>
  bool Equal(T const& lhs, T const& rhs);
  template <typename T>
  bool Equal(std::vector<T> const& lhs, std::vector<T> const& rhs);
}

template <typename T>
bool ConnectX::Equal(T const& lhs, T const& rhs) {
  return lhs == rhs;
}

template <typename T>
bool ConnectX::Equal(std::vector<T> const& lhs, std::vector<T> const& rhs) {
  auto const size = lhs.size();
  if (size != rhs.size()) {
    return false;
  }
  for (std::remove_cv_t<decltype(size)> i = 0; i < size; ++i) {
    if (!Equal(lhs[i], rhs[i])) {
      return false;
    }
  }
  return true;
}

#endif // #ifndef _CONNECT_X_TYPES_HPP_
