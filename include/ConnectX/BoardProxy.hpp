#ifndef _CONNECT_X_BOARD_PROXY_HPP_
#define _CONNECT_X_BOARD_PROXY_HPP_

#include "IBoard.hpp"

namespace ConnectX
{
  class BoardProxy : public IBoard
  {
  public:
    BoardProxy(IBoard& board);

  private:
    IBoard& m_board;
  };
}

#endif // #ifndef _CONNECT_X_BOARD_PROXY_HPP_
