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
  bool const allPassed = Equal<ConnectX::IController const*>(proxy.GetCurrentController(), &RefereeImpl::valueGetCurrentController)
    && Equal(proxy.GetControllerCount(), RefereeImpl::valueGetControllerCount)
    && Equal(proxy.GetHistory(0), RefereeImpl::valueGetHistory)
    && Equal(proxy.GetHistoryRange(0,0), RefereeImpl::valueGetHistoryRange)
    && Equal(proxy.GetHistorySize(), RefereeImpl::valueGetHistorySize)
    && Equal(proxy.PlayGame(), RefereeImpl::valuePlayGame);

  return allPassed ? 0 : -1;
}