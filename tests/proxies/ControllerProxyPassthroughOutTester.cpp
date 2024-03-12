#include <cstdio>
#include "ZeroReferee.hpp"
#include "ZeroBoard.hpp"
#include "ControllerPassthroughImpl.hpp"

// Expecting return 0
int ControllerProxyPassthroughOutTester(int argc, char** const argv) {
  ControllerProxyResults passthroughResults;
  ControllerImpl impl(passthroughResults);
  ConnectX::ControllerProxy proxy(impl);

  ZeroReferee referee;
  ZeroBoard board;

  using ConnectX::Equal;
  bool const allPassed = Equal(proxy.GetMove(referee, board), ControllerImpl::valueGetMove)
    && Equal<ConnectX::IController*>(&proxy.GetController(), &impl);

  return allPassed ? 0 : -1;
}