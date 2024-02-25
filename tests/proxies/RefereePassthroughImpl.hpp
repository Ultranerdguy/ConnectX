#ifndef _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_
#define _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_

#include "ConnectX/RefereeProxy.hpp"
#include "ZeroController.hpp"

// For storing results of each proxy passthrough call
struct RefereeProxyResults {
  ConnectX::IController* addPlayer = nullptr;
  ConnectX::IBoard* setBoard = nullptr;
  bool getCurrentPlayer = false;
  bool playGame = false;
};

// IBoard implementation that does nothing but sets the results to true
struct RefereeImpl : public ConnectX::IReferee {
  static ZeroController valueGetCurrentPlayer;
  static ZeroController valuePlayGame;

  RefereeImpl(RefereeProxyResults& r);
    
  virtual void AddPlayer(ConnectX::IController& player) override;
  virtual void SetBoard(ConnectX::IBoard& board) override;
  virtual ConnectX::IController* GetCurrentPlayer() const override;
  virtual ConnectX::IController* PlayGame() override;

private:
  RefereeProxyResults& results;
};

#endif // #ifndef _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_