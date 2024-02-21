#include <cstdio>
#include "ConnectX/RefereeProxy.hpp"
#include "ZeroBoard.hpp"
#include "ZeroController.hpp"

// For storing results of each proxy passthrough call
struct Results {
  bool addPlayer = false;
  bool setBoard = false;
  bool getCurrentPlayer = false;
  bool playGame = false;
};

// IBoard implementation that does nothing but sets the results to true
struct RefereeImpl : public ConnectX::IReferee {
  RefereeImpl(Results& r)
    : results(r)
  {
  }
    
  virtual void AddPlayer(ConnectX::IController& player) override {
    results.addPlayer = true;
  }
  virtual void SetBoard(ConnectX::IBoard& board) override {
    results.setBoard = true;
  }
  virtual ConnectX::IController* GetCurrentPlayer() const override {
    results.getCurrentPlayer = true;
    return nullptr;
  }
  virtual ConnectX::IController* PlayGame() override {
    results.playGame = true;
    return nullptr;
  }

private:
  Results& results;
};

// Expecting return 0
// Build errors (such as unimplemented methods from the interface) will fail test
int main() {
  Results passthroughResults;
  RefereeImpl impl(passthroughResults);
  ConnectX::RefereeProxy proxy(impl);

  ZeroBoard board;
  ZeroController controller;

  proxy.AddPlayer(controller);
  proxy.SetBoard(board);
  proxy.GetCurrentPlayer();
  proxy.PlayGame();

  bool const allPassed = passthroughResults.addPlayer
    && passthroughResults.setBoard
    && passthroughResults.getCurrentPlayer
    && passthroughResults.playGame;

  return allPassed ? 0 : -1;
}