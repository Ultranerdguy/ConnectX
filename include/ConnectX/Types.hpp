#ifndef _CONNECT_X_TYPES_HPP_
#define _CONNECT_X_TYPES_HPP_

#include <cstdint>
#include <vector>

namespace ConnectX {
  using VectorComponent = std::int64_t; // A position in one dimension of the board
  using Vector = std::vector<VectorComponent>; // An N dimensional position vector

  using Token = std::uint64_t;
  using TokenBuffer = std::vector<Token>;
}

#endif // #ifndef _CONNECT_X_TYPES_HPP_
