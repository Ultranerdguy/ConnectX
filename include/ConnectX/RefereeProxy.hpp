#ifndef _CONNECT_X_REFEREE_PROXY_HPP_
#define _CONNECT_X_REFEREE_PROXY_HPP_

#include "IReferee.hpp"

namespace ConnectX
{
  class RefereeProxy : public IReferee
  {
  public:
    RefereeProxy(IReferee& referee);
    
    virtual void AddPlayer(IController& player) override;
    virtual void SetBoard(IBoard& board) override;
    virtual IController* GetCurrentPlayer() const override;
    virtual IController* PlayGame() override;

  private:
    IReferee& m_referee;
  };
}

#endif // #ifndef _CONNECT_X_REFEREE_PROXY_HPP_
