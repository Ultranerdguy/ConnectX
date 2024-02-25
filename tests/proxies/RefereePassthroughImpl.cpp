#include "RefereePassthroughImpl.hpp"

ZeroController RefereeImpl::valueGetCurrentPlayer{};
ZeroController RefereeImpl::valuePlayGame{};

RefereeImpl::RefereeImpl(RefereeProxyResults& r)
  : results(r)
{
}
  
void RefereeImpl::AddPlayer(ConnectX::IController& player) {
  results.addPlayer = &player;
}
void RefereeImpl::SetBoard(ConnectX::IBoard& board) {
  results.setBoard = &board;
}
ConnectX::IController* RefereeImpl::GetCurrentPlayer() const {
  results.getCurrentPlayer = true;
  return &valueGetCurrentPlayer;
}
ConnectX::IController* RefereeImpl::PlayGame() {
  results.playGame = true;
  return &valuePlayGame;
}