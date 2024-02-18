#ifndef _CONNECT_X_TYPES_HPP_
#define _CONNECT_X_TYPES_HPP_

#include <cstdint>
#include <vector>

namespace ConnectX {
  using VectorComponent = std::uint64_t; // A position in one dimension of the board
  using Vector = std::vector<VectorComponent>; // An N dimensional position vector
  using VectorIndex = std::uint64_t; // Index type into a Vector.

  template <typename TToken>
  concept TokenType;
}

#endif // #ifndef _CONNECT_X_TYPES_HPP_
