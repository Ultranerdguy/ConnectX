#ifndef _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_
#define _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_

#include "ConnectX/RefereeProxy.hpp"
#include "ZeroController.hpp"

// For storing results of each proxy passthrough call
struct RefereeProxyResults {
  ConnectX::IController* addController = nullptr;
  ConnectX::IBoard* setBoard = nullptr;
  bool getCurrentController = false;
  bool getControllerCount = false;
  std::size_t getHistory = 0;
  struct {
    std::size_t start = 0;
    std::size_t size = 0;
  } getHistoryRange;
  bool getHistorySize = 0;
  bool playGame = false;
};

// IBoard implementation that does nothing but sets the results to true
struct RefereeImpl : public ConnectX::IReferee {
  static ZeroController valueGetCurrentController;
  static std::size_t valueGetControllerCount;
  static ConnectX::SingleMove valueGetHistory;
  static std::vector<ConnectX::SingleMove> valueGetHistoryRange;
  static std::size_t valueGetHistorySize;
  static std::vector<ConnectX::IController*> valuePlayGame;

  RefereeImpl(RefereeProxyResults& r);
    
  virtual void AddController(ConnectX::IController& controller) override;
  virtual void SetBoard(ConnectX::IBoard& board) override;
  virtual ConnectX::IController* GetCurrentController() const override;
  virtual std::size_t GetControllerCount() const override;
  virtual ConnectX::SingleMove GetHistory(std::size_t const index) const override;
  virtual std::vector<ConnectX::SingleMove> GetHistoryRange(std::size_t const start, std::size_t const size) const override;
  virtual std::size_t GetHistorySize() const override;
  virtual std::vector<ConnectX::IController*> PlayGame() override;

private:
  RefereeProxyResults& results;
};

#endif // #ifndef _CONNECT_X_TESTS_PROXIES_REFEREE_IMPLEMENTATION_HPP_