#ifndef _CONNECT_X_REFEREE_PROXY_HPP_
#define _CONNECT_X_REFEREE_PROXY_HPP_

#include "IReferee.hpp"

namespace ConnectX
{
  class RefereeProxy : public IReferee
  {
  public:
    RefereeProxy(IReferee& referee);

  private:
    IReferee& m_referee;
  };
}

#endif // #ifndef _CONNECT_X_REFEREE_PROXY_HPP_
