#ifndef _CONNECT_X_IBOARD_HPP_
#define _CONNECT_X_IBOARD_HPP_

#include <vector>
#include "Types.hpp"

namespace ConnectX {
  using TokenBuffer = std::vector<Token>;
  struct IBoard {
    virtual VectorIndex GetDimensions() const = 0;
    virtual VectorComponent GetScale(VectorIndex const index) const = 0;
    virtual Token GetAt(Vector& const position) const = 0;
    virtual TokenBuffer GetRange(Vector& const start, Vector& const size) const = 0;
    virtual bool DropToken(Vector& const position, Token const token) = 0;
  };
}

#endif // #ifndef _CONNECT_X_IBOARD_HPP_
