#ifndef _CONNECT_X_DENSE_BOARD_HPP_
#define _CONNECT_X_DENSE_BOARD_HPP_

#include "IBoard.hpp"

namespace ConnectX {
  class DenseBoard : public IBoard {
  public:
  private:
    TokenBuffer m_grid;
  };
}

#endif // #ifndef _CONNECT_X_DENSE_BOARD_HPP_
