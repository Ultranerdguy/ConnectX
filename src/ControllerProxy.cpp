#include "ConnectX/ControllerProxy.hpp"

ConnectX::ControllerProxy::ControllerProxy(ConnectX::IController& controller)
  : m_controller(controller)
{}

void ConnectX::ControllerProxy::EndGame(bool const win)
{
  return m_controller.EndGame(win);
}

ConnectX::Input ConnectX::ControllerProxy::GetInput(ConnectX::Board const& board, std::vector<ConnectX::Input> const& badInputs)
{
  return m_controller.GetInput(board, badInputs);
}
