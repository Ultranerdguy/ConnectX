#ifndef _CONNECT_4_TYPES_HPP_
#define _CONNECT_4_TYPES_HPP_

#include <vector>

namespace Connect4
{
  using Input = std::size_t;

  // Token{} is no player
  // Valid tokens can be created by pre-incrementing
  // Tokens only need to support equality and pre-increment
  using Token = unsigned int;
}

#endif // #ifndef _CONNECT_4_TYPES_HPP_
