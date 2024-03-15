#ifndef _CONNECT_X_TEST_QUERY_REFEREE_HPP_
#define _CONNECT_X_TEST_QUERY_REFEREE_HPP_

#include "ConnectX/IReferee.hpp"

class QueryReferee : public ConnectX::IReferee {
public:
  static std::vector<ConnectX::SingleMove> history;
  static constexpr char expectedHistory[] = "5\t-\t7, 6, 5\n3\t-\t2, 3, 4\n";

  virtual void AddController(ConnectX::IController& controller) override;
  virtual void SetBoard(ConnectX::IBoard& board) override;
  virtual ConnectX::IController* GetCurrentController() const override;
  virtual std::size_t GetControllerCount() const override;
  virtual ConnectX::SingleMove GetHistory(std::size_t const index) const override;
  virtual std::vector<ConnectX::SingleMove> GetHistoryRange(std::size_t const start, std::size_t const size) const override;
  virtual std::size_t GetHistorySize() const override;
  virtual std::vector<ConnectX::IController*> PlayGame() override;
};

#endif // #ifndef _CONNECT_X_TEST_QUERY_REFEREE_HPP_