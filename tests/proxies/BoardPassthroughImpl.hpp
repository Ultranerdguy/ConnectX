#ifndef _CONNECT_X_TESTS_PROXIES_BOARD_IMPLEMENTATION_HPP_
#define _CONNECT_X_TESTS_PROXIES_BOARD_IMPLEMENTATION_HPP_

#include "ConnectX/BoardProxy.hpp"

// For storing results of each proxy passthrough call
struct BoardProxyResults {
  bool getStart = false;
  bool getSize = false;
  ConnectX::Vector getAt{};
  struct {
    ConnectX::Vector position;
    ConnectX::Token token;
  } setAt{};
  struct {
    ConnectX::Vector start;
    ConnectX::SizeVector size;
  } getRange{};
};

struct BoardImpl : public ConnectX::IBoard {
  static ConnectX::Vector valueGetStart;
  static ConnectX::SizeVector valueGetSize;
  static ConnectX::Token valueGetAt;
  static ConnectX::TokenBuffer valueGetRange;

  BoardImpl(BoardProxyResults& r);

  virtual ConnectX::Vector GetStart() const override;
  virtual ConnectX::SizeVector GetSize() const override;
  virtual ConnectX::Token GetAt(ConnectX::Vector const& position) const override;
  virtual void SetAt(ConnectX::Vector const& position, ConnectX::Token const token) override;
  virtual ConnectX::TokenBuffer GetRange(ConnectX::Vector const& start, ConnectX::SizeVector const& size) const override;

private:
  BoardProxyResults& results;
};

#endif // #ifndef _CONNECT_X_TESTS_PROXIES_BOARD_IMPLEMENTATION_HPP_