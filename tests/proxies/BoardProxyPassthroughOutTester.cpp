#include <cstdio>
#include "BoardPassthroughImpl.hpp"

// Tests that data returned from the target board implementation is passed out through the proxy
// Expecting return 0
int BoardProxyPassthroughOutTester(int argc, char** const argv) {
  BoardProxyResults passthroughResults;
  BoardImpl impl(passthroughResults);
  ConnectX::BoardProxy proxy(impl);

  using ConnectX::Equal;
  bool const allPassed = Equal(proxy.GetStart(), BoardImpl::valueGetStart)
    && Equal(proxy.GetSize(), BoardImpl::valueGetSize)
    && Equal(proxy.GetAt({}), BoardImpl::valueGetAt)
    && Equal(proxy.GetRange({},{}), BoardImpl::valueGetRange);

  return allPassed ? 0 : -1;
}