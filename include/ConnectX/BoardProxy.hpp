#ifndef _CONNECT_X_BOARD_PROXY_HPP_
#define _CONNECT_X_BOARD_PROXY_HPP_

#include "IBoard.hpp"

namespace ConnectX
{
  class BoardProxy : public IBoard
  {
  public:
    BoardProxy(IBoard& board);
    
    virtual Vector GetScale() const override;
    virtual Token GetAt(Vector const& position) const override;
    virtual void SetAt(Vector const& position, Token const token) override;
    virtual TokenBuffer GetRange(Vector const& start, Vector const& size) const override;

  private:
    IBoard& m_board;
  };
}

#endif // #ifndef _CONNECT_X_BOARD_PROXY_HPP_
