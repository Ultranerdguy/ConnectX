#ifndef _CONNECT_4_CONTROLLER_HPP_
#define _CONNECT_4_CONTROLLER_HPP_

#include "Connect4Types.hpp"
#include "Connect4Board.hpp"

namespace Connect4
{
  struct IController
  {
    virtual Input GetInput(Board const& board, std::vector<Input> const& badInputs) = 0;
    virtual void EndGame(bool const win) = 0;
  };
}

#endif // #ifndef _CONNECT_4_CONTROLLER_HPP_
