#include "ConnectX/Game.hpp"

ConnectX::Game::Game(std::size_t const width, std::size_t const height)
{
  m_board.SetSize(width, height); // Standard board size
}

ConnectX::Token ConnectX::Game::PlayRound()
{
  std::vector<Input> badInputs;
  for (std::size_t i = 0; i < m_board.GetWidth(); ++i)
  {
    if (m_board.GetAt(i,m_board.GetHeight()-1) != Token{}) badInputs.push_back(i);
  }
  Input move = m_players[m_currentPlayerIndex].pPlayer->GetInput(m_board, badInputs);
  m_board.DropToken(move, m_players[m_currentPlayerIndex].token);
  ++m_currentPlayerIndex %= m_players.size();

  if (m_board.IsFull())
  {
    Token id{};
    return --id;
  }
  Token const winner = m_board.GetWinner();
  if (winner != Token{})
  {
    for (auto const& player : m_players)
    {
      player.pPlayer->EndGame(player.token == winner);
    }
  }
  return winner;
}

ConnectX::Board const& ConnectX::Game::GetBoard() const
{
  return m_board;
}
