#include "ConnectX/Game.hpp"

std::vector<ConnectX::IController*> ConnectX::Game::RunGame() {
  if (!m_referee || !m_board) {
    return {};
  }

  m_referee->SetBoard(*m_board);

  for (auto& pPlayer : m_players) {
    if (pPlayer) {
      m_referee->AddController(*pPlayer);
    }
  }

  return m_referee->PlayGame();
}