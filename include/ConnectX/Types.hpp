#ifndef _CONNECT_X_TYPES_HPP_
#define _CONNECT_X_TYPES_HPP_

#include <cstdint>
#include <vector>
#include <iostream>
#include "Macros.hpp"

namespace ConnectX {
  // Foward declerations
  struct IController;

  using VectorComponent = std::int64_t; // A position in one dimension of the board

  // An N dimensional position vector
  class Vector : public std::vector<VectorComponent> {
  public:
    using std::vector<VectorComponent>::vector;
  };

  using Token = std::uint64_t;
  // A buffer for tokens
  class TokenBuffer : public std::vector<Token> {
  public:
    using std::vector<Token>::vector;
  };

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

std::istream& operator>>(std::istream& input, ConnectX::Vector& vector);
std::ostream& operator<<(std::ostream& output, ConnectX::Vector const& vector);

#endif // #ifndef _CONNECT_X_TYPES_HPP_
