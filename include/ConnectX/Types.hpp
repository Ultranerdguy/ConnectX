#ifndef _CONNECT_X_TYPES_HPP_
#define _CONNECT_X_TYPES_HPP_

#include <cstdint>
#include <vector>

namespace ConnectX {
  // Foward declerations
  struct IController;

  using VectorComponent = std::int64_t; // A position in one dimension of the board
  using Vector = std::vector<VectorComponent>; // An N dimensional position vector

  using Token = std::uint64_t;
  using TokenBuffer = std::vector<Token>;

  struct SingleMove {
    Token token = 0;
    IController* pController = nullptr;
    Vector position;
  };

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

template <> 
bool ConnectX::Equal<ConnectX::SingleMove>(ConnectX::SingleMove const& lhs, ConnectX::SingleMove const& rhs);

#endif // #ifndef _CONNECT_X_TYPES_HPP_
