#include <cstdio>
#include "ConnectX/BoardProxy.hpp"

// For storing results of each proxy passthrough call
struct Results {
  bool getScale = false;
  bool getAt = false;
  bool setAt = false;
  bool getRange = false;
};

// IBoard implementation that does nothing but sets the results to true
struct BoardImpl : public ConnectX::IBoard {
  BoardImpl(Results& r)
    : results(r)
  {
  }

  virtual ConnectX::Vector GetScale() const override {
    results.getScale = true;
    return {};
  }
  virtual ConnectX::Token GetAt(ConnectX::Vector const& position) const override {
    results.getAt = true;
    return 0;
  }
  virtual void SetAt(ConnectX::Vector const& position, ConnectX::Token const token) override {
    results.setAt = true;
  }
  virtual ConnectX::TokenBuffer GetRange(ConnectX::Vector const& start, ConnectX::Vector const& size) const override {
    results.getRange = true;
    return {};
  }

private:
  Results& results;
};

// Expecting return 0
// Build errors (such as unimplemented methods from the interface) will fail test
int main() {
  Results passthroughResults;
  BoardImpl impl(passthroughResults);
  ConnectX::BoardProxy proxy(impl);

  proxy.GetScale();
  proxy.GetAt({});
  proxy.SetAt({},0);
  proxy.GetRange({},{});

  bool const allPassed = passthroughResults.getScale
    && passthroughResults.getAt
    && passthroughResults.setAt
    && passthroughResults.getRange;

  return allPassed ? 0 : -1;
}