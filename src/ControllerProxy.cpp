#include "ConnectX/ControllerProxy.hpp"
#include "ConnectX/IReferee.hpp"
#include "ConnectX/IBoard.hpp"

ConnectX::ControllerProxy::ControllerProxy(ConnectX::IController& controller)
  : m_controller(controller)
{
}

void ConnectX::ControllerProxy::AssignToken(Token const token) {
  m_controller.AssignToken(token);
}

ConnectX::Vector ConnectX::ControllerProxy::GetMove(IReferee const& referee, IBoard const& board) {
  return m_controller.GetMove(referee, board);
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

ConnectX::IController& ConnectX::ControllerProxy::GetController() {
  return m_controller.GetController();
}