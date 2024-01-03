#include <iostream>
#include <algorithm>
#include <thread>
#include <cmath>
#include <cstring>
#include "Connect4Game.hpp"
#include "Connect4IController.hpp"

class TestController : public Connect4::IController
{
public:
  TestController(std::size_t const column)
    : m_column(column)
  {}

  virtual Connect4::Input GetInput(Connect4::Board const& board, std::vector<Connect4::Input> const& badInputs) override
  {
    return ((m_column += 2) %= board.GetWidth());
  }

  virtual void EndGame(bool const win) override {}

  std::size_t m_column = 0;
};

void PrintBoard(Connect4::Board const& board, std::size_t const width, std::size_t const height)
{
  std::size_t const cellWidth = ((width+1)/board.GetWidth())-1;
  std::size_t const cellHeight = ((height+1)/board.GetHeight())-1;
  std::size_t const bufferWidth = (cellWidth+1)*board.GetWidth() - 1;
  std::size_t const bufferHeight = (cellHeight+1)*board.GetHeight() - 1;
  std::vector<char> buffer(bufferWidth*bufferHeight, ' ');
  Connect4::Token id{};
  Connect4::Token const xID = ++id;
  Connect4::Token const oID = ++id;
  for (std::size_t j=0; j<bufferHeight; ++j)
  {
    if (j%(cellHeight+1) == cellHeight)
    {
      std::memset(buffer.data()+j*bufferWidth, '-', bufferWidth);
      for (std::size_t i=cellWidth; i<bufferWidth; i += (cellWidth+1)) buffer[j*bufferWidth+i] = '+';
      continue;
    }

    for (std::size_t i=0; i<bufferWidth; ++i)
    {
      char c = ' ';
      if (i%(cellWidth+1) == cellWidth) c = '|';
      else
      {
        // Cell content
        std::size_t const cellIndexX = i/(cellWidth+1);
        std::size_t const cellIndexY = board.GetHeight()  - j/(cellHeight+1) - 1;
        if (board.GetAt(cellIndexX, cellIndexY) == xID) c ='@';
        else if (board.GetAt(cellIndexX, cellIndexY) == oID) c = '.';
      }
      buffer[j*bufferWidth + i] = c;
    }
  }

  for (std::size_t j=0; j<bufferHeight; ++j)
  {
    std::cout.write(buffer.data()+j*bufferWidth, bufferWidth);
    std::cout.put('\n');
  }
  std::cout.put('\n');
}

int main()
{
  Connect4::Game game;
  Connect4::Token id{};
  game.AddPlayer<TestController>(++id, 0);
  game.AddPlayer<TestController>(++id, 1);
  
  constexpr std::size_t bufferWidth = 90;
  constexpr std::size_t bufferHeight = 48;
  PrintBoard(game.GetBoard(), bufferWidth,bufferHeight);
  while (true)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto const t = game.PlayRound();
    PrintBoard(game.GetBoard(), bufferWidth,bufferHeight);
    if (t != Connect4::Token{})
    {
      std::cout << t << " wins\n";
      break;
    }
  }

  return 0;
}
