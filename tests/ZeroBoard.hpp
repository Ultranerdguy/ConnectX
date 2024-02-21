#ifndef _CONNECT_X_ZERO_BOARD_HPP_
#define _CONNECT_X_ZERO_BOARD_HPP_

#include "ConnectX/IBoard.hpp"

// Simple board implementation that does nothing, for the purposes of passing a valid board around
class ZeroBoard : public ConnectX::IBoard
{ 
public:
  virtual ConnectX::Vector GetScale() const override {
    return {};
  }
  virtual ConnectX::Token GetAt(ConnectX::Vector const& position) const override {
    return static_cast<ConnectX::Token>(0);
  }
  virtual void SetAt(ConnectX::Vector const& position, ConnectX::Token const token) override {
  }
  virtual ConnectX::TokenBuffer GetRange(ConnectX::Vector const& start, ConnectX::Vector const& size) const override {
    return {};
  }
};

#endif // #ifndef _CONNECT_X_ZERO_BOARD_HPP_
