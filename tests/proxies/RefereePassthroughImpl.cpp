#include "RefereePassthroughImpl.hpp"

ZeroController RefereeImpl::valueGetCurrentController{};
std::size_t RefereeImpl::valueGetControllerCount = 7;
ConnectX::SingleMove RefereeImpl::valueGetHistory{};
std::vector<ConnectX::SingleMove> RefereeImpl::valueGetHistoryRange{};
std::size_t RefereeImpl::valueGetHistorySize = 9;
std::vector<ConnectX::IController*> RefereeImpl::valuePlayGame{};

RefereeImpl::RefereeImpl(RefereeProxyResults& r)
  : results(r)
{
}
  
void RefereeImpl::AddController(ConnectX::IController& controller) {
  results.addController = &controller;
}
void RefereeImpl::SetBoard(ConnectX::IBoard& board) {
  results.setBoard = &board;
}
ConnectX::IController* RefereeImpl::GetCurrentController() const {
  results.getCurrentController = true;
  return &valueGetCurrentController;
}
std::size_t RefereeImpl::GetControllerCount() const {
  results.getControllerCount = true;
  return valueGetControllerCount;
}
ConnectX::SingleMove RefereeImpl::GetHistory(std::size_t const index) const {
  results.getHistory = index;
  return valueGetHistory;
}
std::vector<ConnectX::SingleMove> RefereeImpl::GetHistoryRange(std::size_t const start, std::size_t const size) const {
  results.getHistoryRange.start = start;
  results.getHistoryRange.size = size;
  return valueGetHistoryRange;
}
std::size_t RefereeImpl::GetHistorySize() const {
  results.getHistorySize = true;
  return valueGetHistorySize;
}
std::vector<ConnectX::IController*> RefereeImpl::PlayGame() {
  results.playGame = true;
  return valuePlayGame;
}