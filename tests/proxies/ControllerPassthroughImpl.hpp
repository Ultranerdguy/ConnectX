#ifndef _CONNECT_X_TESTS_PROXIES_CONTROLLER_IMPLEMENTATION_HPP_
#define _CONNECT_X_TESTS_PROXIES_CONTROLLER_IMPLEMENTATION_HPP_

#include "ConnectX/ControllerProxy.hpp"

// For storing results of each proxy passthrough call
struct ControllerProxyResults {
  ConnectX::Token assignToken{};
  ConnectX::IBoard const* getMove = nullptr;
  bool onWin = false;
  bool onLose = false;
  bool onDraw = false;
};

struct ControllerImpl : public ConnectX::IController {
  static ConnectX::Vector valueGetMove;

  ControllerImpl(ControllerProxyResults& r);
  
  virtual void AssignToken(ConnectX::Token const token) override;
  virtual ConnectX::Vector GetMove(ConnectX::IBoard const& board) override;
  virtual void OnWin() override;
  virtual void OnLose() override;
  virtual void OnDraw() override;

private:
  ControllerProxyResults& results;
};

#endif // #ifndef _CONNECT_X_TESTS_PROXIES_CONTROLLER_IMPLEMENTATION_HPP_