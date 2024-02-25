#include <cstdio>
#include "ZeroBoard.hpp"
#include "ControllerPassthroughImpl.hpp"

// Expecting return 0
int ControllerProxyPassthroughOutTester(int argc, char** const argv) {
  ControllerProxyResults passthroughResults;
  ControllerImpl impl(passthroughResults);
  ConnectX::ControllerProxy proxy(impl);

  ZeroBoard board;

  using ConnectX::Equal;
  bool const allPassed = Equal(proxy.GetMove(board), ControllerImpl::valueGetMove);

  return allPassed ? 0 : -1;
}