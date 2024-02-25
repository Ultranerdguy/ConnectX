#ifndef _CONNECT_X_TESTS_ZERO_CONTROLLER_HPP_
#define _CONNECT_X_TESTS_ZERO_CONTROLLER_HPP_

#include "ConnectX/IController.hpp"

// Simple controller implementation that does nothing, for the purposes of passing a valid controller around
class ZeroController : public ConnectX::IController
{ 
public:
  virtual void AssignToken(ConnectX::Token const token) override {
  }
  virtual ConnectX::Vector GetMove(ConnectX::IBoard const& board) override {
    return {};
  }
  virtual void OnWin() override {
  }
  virtual void OnLose() override {
  }
  virtual void OnDraw() override {
  }
};

#endif // #ifndef _CONNECT_X_TESTS_ZERO_CONTROLLER_HPP_
