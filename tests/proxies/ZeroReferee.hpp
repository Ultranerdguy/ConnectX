#ifndef _CONNECT_X_TESTS_ZERO_REFEREE_HPP_
#define _CONNECT_X_TESTS_ZERO_REFEREE_HPP_

#include "ConnectX/IReferee.hpp"
#include "ConnectX/IController.hpp"
#include "ConnectX/IBoard.hpp"

// Simple controller implementation that does nothing, for the purposes of passing a valid controller around
class ZeroReferee : public ConnectX::IReferee
{ 
public:
  virtual void AddController(ConnectX::IController& controller) override {
  }
  virtual void SetBoard(ConnectX::IBoard& board) override {
  }
  virtual ConnectX::IController* GetCurrentController() const override {
    return nullptr;
  }
  virtual std::size_t GetControllerCount() const override {
    return 0;
  }
  virtual ConnectX::SingleMove GetHistory(std::size_t const index) const override {
    return {};
  }
  virtual std::vector<ConnectX::SingleMove> GetHistoryRange(std::size_t const start, std::size_t const size) const override {
    return {};
  }
  virtual std::size_t GetHistorySize() const override {
    return 0;
  }
  virtual std::vector<ConnectX::IController*> PlayGame() override {
    return {};
  }
};

#endif // #ifndef _CONNECT_X_TESTS_ZERO_REFEREE_HPP_
