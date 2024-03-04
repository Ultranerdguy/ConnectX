#include "ConnectX/RefereeProxy.hpp"

ConnectX::RefereeProxy::RefereeProxy(ConnectX::IReferee& referee)
  : m_referee(referee)
{
}

void ConnectX::RefereeProxy::AddController(ConnectX::IController& controller) {
  m_referee.AddController(controller);
}

void ConnectX::RefereeProxy::SetBoard(ConnectX::IBoard& board) {
  m_referee.SetBoard(board);
}

ConnectX::IController* ConnectX::RefereeProxy::GetCurrentController() const {
  return m_referee.GetCurrentController();
}

std::size_t ConnectX::RefereeProxy::GetControllerCount() const {
  return m_referee.GetControllerCount();
}

ConnectX::SingleMove ConnectX::RefereeProxy::GetHistory(std::size_t const index) const {
  return m_referee.GetHistory(index);
}

std::vector<ConnectX::SingleMove> ConnectX::RefereeProxy::GetHistoryRange(std::size_t const start, std::size_t const size) const {
  return m_referee.GetHistoryRange(start, size);
}

std::size_t ConnectX::RefereeProxy::GetHistorySize() const {
  return m_referee.GetHistorySize();
}

std::vector<ConnectX::IController*> ConnectX::RefereeProxy::PlayGame() {
  return m_referee.PlayGame();
}