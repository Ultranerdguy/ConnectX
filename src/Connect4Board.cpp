#include "Connect4Board.hpp"
#include <stdexcept>

void Connect4::Board::SetSize(std::size_t const width, std::size_t const height)
{
  m_width = width;
  m_height = height;
  m_grid.resize(width*height, Token{});
}

std::size_t Connect4::Board::GetWidth() const
{
  return m_width;
}

std::size_t Connect4::Board::GetHeight() const
{
  return m_height;
}

bool Connect4::Board::DropToken(std::size_t const column, Token const token)
{
  // Out of range exception
  if (column < 0 || column >= GetWidth()) throw std::range_error("Connect4::Board::DropToken invalid column index");
  // Column full return
  if (m_grid[(column+1)*GetHeight() - 1] != Token{}) return false;

  // Iterate from bottom to top till we find an empty space
  for (std::size_t i=0; i<GetHeight(); ++i)
  {
    std::size_t index = column*GetHeight() + i;
    if (m_grid[index] == Token{})
    {
      m_grid[index] = token;
      break;
    }
  }
        
  return true;
}

bool Connect4::Board::IsFull() const
{
  for (std::size_t i=0; i<GetWidth(); ++i)
  {
    if (GetAt(i, GetHeight()-1) == Token{}) return false;
  }
  return true;
}

Connect4::Token Connect4::Board::GetWinner() const 
{
  Token winner = GetWinner_Vertical();
  if (winner != Token{}) return winner;
  winner = GetWinner_Horizontal();
  if (winner != Token{}) return winner;
  winner = GetWinner_ForwardDiagonal();
  if (winner != Token{}) return winner;
  winner = GetWinner_BackwardDiagonal();
  return winner;
}

std::vector<Connect4::Token> const& Connect4::Board::GetGrid() const
{
  return m_grid;
}

Connect4::Token Connect4::Board::GetAt(std::size_t column, std::size_t row) const
{
  if (column < 0 || column >= GetWidth()) throw std::range_error("Connect4::Board::GetAt invalid column index");
  if (row < 0 || row >= GetWidth()) throw std::range_error("Connect4::Board::GetAt invalid row index");
  
  return m_grid[column*GetHeight() + row];
}

Connect4::Token Connect4::Board::GetWinner_Vertical() const
{
  for (std::size_t column = 0; column < GetWidth(); ++column)
  {
    int runLength = 0;
    Token target{};
    for (std::size_t row = 0; row < GetHeight(); ++row)
    {
      Token current = GetAt(column, row);
      if (current == Token{}) continue;

      if (current == target) ++runLength;
      else runLength = 1;
      target = current;
      if (runLength == 4) return current;
    }
  }
  return Token{};
}

Connect4::Token Connect4::Board::GetWinner_Horizontal() const
{
  for (std::size_t row = 0; row < GetHeight(); ++row)
  {
    int runLength = 0;
    Token target{};
    for (std::size_t column = 0; column < GetWidth(); ++column)
    {
      Token current = GetAt(column, row);
      if (current == Token{}) continue;

      if (current == target) ++runLength;
      else runLength = 1;
      target = current;
      if (runLength == 4) return current;
    }
  }
  return Token{};
}

Connect4::Token Connect4::Board::GetWinner_ForwardDiagonal() const
{
  std::size_t limit = (GetWidth()-3)*(GetHeight()-3);
  for (std::size_t index = 0; index < limit; ++index)
  {
    std::size_t row = index/(GetWidth()-3);
    std::size_t column = index%(GetWidth()-3);
    int runLength = 0;
    Token target{};
    for (std::size_t offset = 0; offset < 4; ++offset)
    {
      Token current = GetAt(column+offset, row+offset);
      if (current == Token{}) break;
      if (current == target) ++runLength;
      else runLength = 1;
      target = current;
      if (runLength == 4) return current;
    }
  }
  return Token{};
}

Connect4::Token Connect4::Board::GetWinner_BackwardDiagonal() const
{
  std::size_t limit = (GetWidth()-3)*(GetHeight()-3);
  for (std::size_t index = 0; index < limit; ++index)
  {
    std::size_t const row = index/(GetWidth()-3);
    std::size_t const column = GetWidth() - 1 - index%(GetWidth()-3);
    int runLength = 0;
    Token target{};
    for (std::size_t offset = 0; offset < 4; ++offset)
    {
      Token current = GetAt(column-offset, row+offset);
      if (current == Token{}) break;
      if (current == target) ++runLength;
      else runLength = 1;
      target = current;
      if (runLength == 4) return current;
    }
  }
  return Token{};
}
