#include <cstdio>
#include "RefereePassthroughImpl.hpp"
#include "ZeroBoard.hpp"
#include "ZeroController.hpp"

// Expecting return 0
int RefereeProxyPassthroughOutTester(int argc, char** const argv) {
  RefereeProxyResults passthroughResults;
  RefereeImpl impl(passthroughResults);
  ConnectX::RefereeProxy proxy(impl);

  ZeroController controller;
  ZeroBoard board;

  using ConnectX::Equal;
  bool const allPassed = Equal<ConnectX::IController const*>(proxy.GetCurrentPlayer(), &RefereeImpl::valueGetCurrentPlayer)
    && Equal<ConnectX::IController const*>(proxy.PlayGame(), &RefereeImpl::valuePlayGame);

  return allPassed ? 0 : -1;
}