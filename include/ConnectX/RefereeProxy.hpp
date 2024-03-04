#ifndef _CONNECT_X_REFEREE_PROXY_HPP_
#define _CONNECT_X_REFEREE_PROXY_HPP_

#include "IReferee.hpp"

namespace ConnectX
{
  class RefereeProxy : public IReferee
  {
  public:
    RefereeProxy(IReferee& referee);
    
    virtual void AddController(IController& controller) override;
    virtual void SetBoard(IBoard& board) override;
    virtual IController* GetCurrentController() const override;
    virtual std::size_t GetControllerCount() const override;
    virtual SingleMove GetHistory(std::size_t const index) const override;
    virtual std::vector<SingleMove> GetHistoryRange(std::size_t const start, std::size_t const size) const override;
    virtual std::size_t GetHistorySize() const override;
    virtual std::vector<IController*> PlayGame() override;

  private:
    IReferee& m_referee;
  };
}

#endif // #ifndef _CONNECT_X_REFEREE_PROXY_HPP_
