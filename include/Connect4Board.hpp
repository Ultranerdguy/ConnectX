#ifndef _CONNECT_4_BOARD_HPP_
#define _CONNECT_4_BOARD_HPP_

#include <vector>
#include "Connect4Types.hpp"

namespace Connect4
{
  class Board
  {
  public:
    Board() = default;

    void SetSize(std::size_t const width, std::size_t const height); 
    std::size_t GetWidth() const;
    std::size_t GetHeight() const;

    bool DropToken(std::size_t const column, Token const token);

    bool IsFull() const;
    Token GetWinner() const;

    std::vector<Token> const& GetGrid() const;
    Token GetAt(std::size_t column, std::size_t row) const;
    
  private:
    Token GetWinner_Vertical() const;
    Token GetWinner_Horizontal() const;
    Token GetWinner_ForwardDiagonal() const;
    Token GetWinner_BackwardDiagonal() const;

    std::vector<Token> m_grid; // Column major
    std::size_t m_width = 0;
    std::size_t m_height = 0;
  };
}

#endif // #ifndef _CONNECT_4_BOARD_HPP_
