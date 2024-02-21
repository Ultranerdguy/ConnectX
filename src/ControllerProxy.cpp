#include "ConnectX/ControllerProxy.hpp"

ConnectX::ControllerProxy::ControllerProxy(ConnectX::IController& controller)
  : m_controller(controller)
{
}

void ConnectX::ControllerProxy::AssignToken(Token const token) {
  m_controller.AssignToken(token);
}

ConnectX::Vector ConnectX::ControllerProxy::GetMove(IBoard const& board) {
  return m_controller.GetMove(board);
}

void ConnectX::ControllerProxy::OnWin() {
  m_controller.OnWin();
}

void ConnectX::ControllerProxy::OnLose() {
  m_controller.OnLose();
}

void ConnectX::ControllerProxy::OnDraw() {
  m_controller.OnDraw();
}