#include "ControllerPassthroughImpl.hpp"

ConnectX::Vector ControllerImpl::valueGetMove = {1,2,3};

ControllerImpl::ControllerImpl(ControllerProxyResults& r) 
  : results(r) 
{
}
void ControllerImpl::AssignToken(ConnectX::Token const token) {
  results.assignToken = token;
}
ConnectX::Vector ControllerImpl::GetMove(ConnectX::IBoard const& board) {
  results.getMove = &board;
  return valueGetMove;
}
void ControllerImpl::OnWin() {
  results.onWin = true;
}
void ControllerImpl::OnLose() {
  results.onLose = true;
}
void ControllerImpl::OnDraw() {
  results.onDraw = true;
}