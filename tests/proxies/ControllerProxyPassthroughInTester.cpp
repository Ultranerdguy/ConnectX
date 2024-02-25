#include <cstdio>
#include "ZeroBoard.hpp"
#include "ControllerPassthroughImpl.hpp"

// Tests that data is passed through the proxy to the target controller implementation
// Expecting return 0
int ControllerProxyPassthroughInTester(int argc, char** const argv) {
  ControllerProxyResults passthroughResults;
  ControllerImpl impl(passthroughResults);
  ConnectX::ControllerProxy proxy(impl);

  ConnectX::Token const queryAssignToken = 7;
  ZeroBoard const queryGetMove;

  proxy.AssignToken(queryAssignToken);
  proxy.GetMove(queryGetMove);
  proxy.OnWin();
  proxy.OnLose();
  proxy.OnDraw();

  using ConnectX::Equal;
  bool const allPassed = Equal(passthroughResults.assignToken, queryAssignToken)
    && Equal<ConnectX::IBoard const*>(passthroughResults.getMove, &queryGetMove)
    && passthroughResults.onWin
    && passthroughResults.onLose
    && passthroughResults.onDraw;

  return allPassed ? 0 : -1;
}