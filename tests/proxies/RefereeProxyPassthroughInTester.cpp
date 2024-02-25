#include <cstdio>
#include "RefereePassthroughImpl.hpp"
#include "ZeroBoard.hpp"
#include "ZeroController.hpp"

// Tests that data is passed through the proxy to the target referee implementation
// Expecting return 0
int RefereeProxyPassthroughInTester(int argc, char** const argv) {
  RefereeProxyResults passthroughResults;
  RefereeImpl impl(passthroughResults);
  ConnectX::RefereeProxy proxy(impl);

  ZeroController controller;
  ZeroBoard board;

  proxy.AddPlayer(controller);
  proxy.SetBoard(board);
  proxy.GetCurrentPlayer();
  proxy.PlayGame();

  using ConnectX::Equal;
  bool const allPassed = Equal<ConnectX::IController const*>(passthroughResults.addPlayer, &controller)
    && Equal<ConnectX::IBoard const*>(passthroughResults.setBoard, &board)
    && passthroughResults.getCurrentPlayer
    && passthroughResults.playGame;

  return allPassed ? 0 : -1;
}