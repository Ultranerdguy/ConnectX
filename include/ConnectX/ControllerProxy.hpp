#ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
#define _CONNECT_X_CONTROLLER_PROXY_HPP_

#include "IController.hpp"

namespace ConnectX
{
  class ControllerProxy : public IController
  {
  public:
    ControllerProxy(IController& controller);

  private:
    IController& m_controller;
  };
}

#endif // #ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
