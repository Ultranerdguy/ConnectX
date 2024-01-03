#include "Connect4ControllerProxy.hpp"

Connect4::ControllerProxy::ControllerProxy(Connect4::IController& controller)
  : m_controller(controller)
{}

void Connect4::ControllerProxy::EndGame(bool const win)
{
  return m_controller.EndGame(win);
}

Connect4::Input Connect4::ControllerProxy::GetInput(Connect4::Board const& board, std::vector<Connect4::Input> const& badInputs)
{
  return m_controller.GetInput(board, badInputs);
}
