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
  ConnectX::Vector const queryGetRangeEnd = {4,5,10};

  proxy.GetStart();
  proxy.GetEnd();
  proxy.GetAt(queryGetAt);
  proxy.SetAt(querySetAtPosition, querySetAtToken);
  proxy.GetRange(queryGetRangeStart, queryGetRangeEnd);

  using ConnectX::Equal;
  bool const allPassed = passthroughResults.getStart
    && passthroughResults.getEnd
    && Equal(passthroughResults.getAt, queryGetAt)
    && Equal(passthroughResults.setAt.position, querySetAtPosition)
    && Equal(passthroughResults.setAt.token, querySetAtToken)
    && Equal(passthroughResults.getRange.start, queryGetRangeStart)
    && Equal(passthroughResults.getRange.end, queryGetRangeEnd);

  return allPassed ? 0 : -1;
}