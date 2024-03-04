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
  std::size_t historyIndex = 3;
  std::size_t historyStart = 5;
  std::size_t historySize = 2;

  proxy.AddController(controller);
  proxy.SetBoard(board);
  proxy.GetCurrentController();
  proxy.GetControllerCount();
  proxy.GetHistory(historyIndex);
  proxy.GetHistoryRange(historyStart, historySize);
  proxy.GetHistorySize();
  proxy.PlayGame();

  using ConnectX::Equal;
  bool const allPassed = Equal<ConnectX::IController const*>(passthroughResults.addController, &controller)
    && Equal<ConnectX::IBoard const*>(passthroughResults.setBoard, &board)
    && passthroughResults.getCurrentController
    && passthroughResults.getControllerCount
    && Equal(passthroughResults.getHistory, historyIndex)
    && Equal(passthroughResults.getHistoryRange.start, historyStart)
    && Equal(passthroughResults.getHistoryRange.size, historySize)
    && passthroughResults.getHistorySize
    && passthroughResults.playGame;

  return allPassed ? 0 : -1;
}