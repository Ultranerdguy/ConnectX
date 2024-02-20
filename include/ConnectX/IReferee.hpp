#ifndef _CONNECT_X_IREFEREE_HPP_
#define _CONNECT_X_IREFEREE_HPP_

#include <concepts>
#include "Types.hpp"
#include "IController.hpp"
#include "IBoard.hpp"

namespace ConnectX {
  struct IReferee {
    virtual void Init(IController* players, std::size_t playerCount, IBoard& board) = 0;
    virtual IController* GetCurrentPlayer() const = 0;
    virtual IController* PlayGame() = 0;
  };

  namespace Concept {
    template <typename T> concept Referee = std::derived_from<T, IReferee>;
  }
}

#endif // #ifndef _CONNECT_X_IREFEREE_HPP_
