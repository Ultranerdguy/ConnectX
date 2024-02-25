#include <cstdio>
#include "BoardPassthroughImpl.hpp"

// Tests that data is passed through the proxy to the target board implementation
// Expecting return 0
int BoardProxyPassthroughInTester(int argc, char** const argv) {
  BoardProxyResults passthroughResults;
  BoardImpl impl(passthroughResults);
  ConnectX::BoardProxy proxy(impl);

  ConnectX::Vector const queryGetAt = {1,3,5};
  ConnectX::Vector const querySetAtPosition = {2,4,6};
  ConnectX::Token const querySetAtToken = 4;
  ConnectX::Vector const queryGetRangeStart = {3,6,9};
  ConnectX::SizeVector const queryGetRangeSize = {1,1,1};

  proxy.GetStart();
  proxy.GetSize();
  proxy.GetAt(queryGetAt);
  proxy.SetAt(querySetAtPosition, querySetAtToken);
  proxy.GetRange(queryGetRangeStart, queryGetRangeSize);

  using ConnectX::Equal;
  bool const allPassed = passthroughResults.getStart
    && passthroughResults.getSize
    && Equal(passthroughResults.getAt, queryGetAt)
    && Equal(passthroughResults.setAt.position, querySetAtPosition)
    && Equal(passthroughResults.setAt.token, querySetAtToken)
    && Equal(passthroughResults.getRange.start, queryGetRangeStart)
    && Equal(passthroughResults.getRange.size, queryGetRangeSize);

  return allPassed ? 0 : -1;
}