#ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
#define _CONNECT_X_CONTROLLER_PROXY_HPP_

#include "IController.hpp"

namespace ConnectX
{
  class ControllerProxy : public IController
  {
  public:
    ControllerProxy(IController& controller);

    virtual void AssignToken(Token const token) override;
    virtual Vector GetMove(IBoard const& board) override;
    virtual void OnWin() override;
    virtual void OnLose() override;
    virtual void OnDraw() override;

  private:
    IController& m_controller;
  };
}

#endif // #ifndef _CONNECT_X_CONTROLLER_PROXY_HPP_
