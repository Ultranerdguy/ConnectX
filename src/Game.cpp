#include "ConnectX/Game.hpp"

ConnectX::IController* ConnectX::Game::RunGame() {
  if (!m_referee || !m_board) {
    return nullptr;
  }

  m_referee->SetBoard(*m_board);

  for (auto& pPlayer : m_players) {
    if (pPlayer) {
      m_referee->AddPlayer(*pPlayer);
    }
  }

  return m_referee->PlayGame();
}