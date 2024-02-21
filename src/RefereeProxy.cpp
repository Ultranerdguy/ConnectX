#include "ConnectX/RefereeProxy.hpp"

ConnectX::RefereeProxy::RefereeProxy(ConnectX::IReferee& referee)
  : m_referee(referee)
{
}

void ConnectX::RefereeProxy::AddPlayer(ConnectX::IController& player) {
  m_referee.AddPlayer(player);
}

void ConnectX::RefereeProxy::SetBoard(ConnectX::IBoard& board) {
  m_referee.SetBoard(board);
}

ConnectX::IController* ConnectX::RefereeProxy::GetCurrentPlayer() const {
  return m_referee.GetCurrentPlayer();
}

ConnectX::IController* ConnectX::RefereeProxy::PlayGame() {
  return m_referee.PlayGame();
}