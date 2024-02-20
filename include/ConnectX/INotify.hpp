#ifndef _CONNECT_X_INOTIFY_HPP_
#define _CONNECT_X_INOTIFY_HPP_

#include "IController.hpp"

namespace ConnectX {
  struct INotify {
    virtual void OnStartGame() = 0;
    virtual void OnStartTurn(IController const&) = 0;
    virtual void OnEndTurn(IController const&) = 0;
    virtual void OnEndGame() = 0;
  };
}

#endif // #ifndef _CONNECT_X_INOTIFY_HPP_
