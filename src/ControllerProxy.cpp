#include "ConnectX/ControllerProxy.hpp"

ConnectX::ControllerProxy::ControllerProxy(ConnectX::IController& controller)
  : m_controller(controller)
{
}

