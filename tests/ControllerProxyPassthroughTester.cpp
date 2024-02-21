#include <cstdio>
#include "ConnectX/ControllerProxy.hpp"
#include "ZeroBoard.hpp"

// For storing results of each proxy passthrough call
struct Results {
  bool assignToken = false;
  bool getMove = false;
  bool onWin = false;
  bool onLose = false;
  bool onDraw = false;
};

// IController that does nothing but set the passed in results to true
struct ControllerImpl : public ConnectX::IController {
  ControllerImpl(Results& r) 
    : results(r) 
  {
  }
  virtual void AssignToken(ConnectX::Token const token) override {
    results.assignToken = true;
  }
  virtual ConnectX::Vector GetMove(ConnectX::IBoard const& board) override {
    results.getMove = true;
    return {};
  }
  virtual void OnWin() override {
    results.onWin = true;
  }
  virtual void OnLose() override {
    results.onLose = true;
  }
  virtual void OnDraw() override {
    results.onDraw = true;
  }

private:
  Results& results;
};

// Expecting return 0
// Build errors (such as unimplemented methods from the interface) will fail test
int main() {
  Results passthroughResults;
  ControllerImpl impl(passthroughResults);
  ConnectX::ControllerProxy proxy(impl);

  ZeroBoard board;

  proxy.AssignToken(0);
  proxy.GetMove(board);
  proxy.OnWin();
  proxy.OnLose();
  proxy.OnDraw();

  bool const allPassed = passthroughResults.assignToken
    && passthroughResults.getMove
    && passthroughResults.onWin
    && passthroughResults.onLose
    && passthroughResults.onDraw;

  return allPassed ? 0 : -1;
}