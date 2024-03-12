#ifndef _CONNECT_X_ICONTROLLER_HPP_
#define _CONNECT_X_ICONTROLLER_HPP_

#include <concepts>
#include "Types.hpp"

namespace ConnectX {
  // Forward declerations
  struct IBoard;
  struct IReferee;
  
  struct IController {
    virtual void AssignToken(Token const token) = 0;
    virtual Vector GetMove(IReferee const& referee, IBoard const& board) = 0;
    virtual void OnWin() = 0;
    virtual void OnLose() = 0;
    virtual void OnDraw() = 0;
    virtual IController& GetController() = 0;
  };

  namespace Concept {
    template <typename T>
    concept Controller = std::derived_from<T, IController>;
  }
}

#endif // #ifndef _CONNECT_X_ICONTROLLER_HPP_
