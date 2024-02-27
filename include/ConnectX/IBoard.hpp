#ifndef _CONNECT_X_IBOARD_HPP_
#define _CONNECT_X_IBOARD_HPP_

#include <concepts>
#include "Types.hpp"

namespace ConnectX {
  struct IBoard {
    virtual Vector GetStart() const = 0;
    virtual SizeVector GetSize() const = 0;
    virtual Token GetAt(Vector const& position) const = 0;
    virtual void SetAt(Vector const& position, Token const token) = 0;
    virtual TokenBuffer GetRange(Vector const& start, SizeVector const& size) const = 0;
  };

  namespace Concept {
    template <typename T>
    concept Board = std::derived_from<T, IBoard>;
  }
}

#endif // #ifndef _CONNECT_X_IBOARD_HPP_
