#ifndef _CONNECT_X_ICONTROLLER_HPP_
#define _CONNECT_X_ICONTROLLER_HPP_

#include "Types.hpp"
#include "IBoard.hpp"

namespace ConnectX {
  struct IController {
    virtual VectorIndex GetInput(IBoard const& board) = 0;
    virtual void EndGame(bool const win) = 0;
  };
}

#endif // #ifndef _CONNECT_X_ICONTROLLER_HPP_
