#ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
#define _CONNECT_X_CONTROLLER_PROXY_HPP_

#include "IController.hpp"

namespace ConnectX
{
  class ControllerProxy : public IController
  {
  public:
    ControllerProxy(IController& controller);

    virtual Input GetInput(Board const& board, std::vector<Input> const& badInputs) override;
    virtual void EndGame(bool const win) override;

  private:
    IController& m_controller;
  };
}

#endif // #ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
