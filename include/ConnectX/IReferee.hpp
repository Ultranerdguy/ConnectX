#ifndef _CONNECT_X_IREFEREE_HPP_
#define _CONNECT_X_IREFEREE_HPP_

#include <concepts>
#include "Types.hpp"


namespace ConnectX {
  // Forward declarations
  struct IController;
  struct IBoard;
  
  struct IReferee {
    virtual void AddController(IController& controller) = 0;
    virtual void SetBoard(IBoard& board) = 0;
    virtual IController* GetCurrentController() const = 0;
    virtual std::size_t GetControllerCount() const = 0;
    virtual SingleMove GetHistory(std::size_t const index) const = 0;
    virtual std::vector<SingleMove> GetHistoryRange(std::size_t const start, std::size_t const size) const = 0;
    virtual std::size_t GetHistorySize() const = 0;
    virtual std::vector<IController*> PlayGame() = 0;
  };

  namespace Concept {
    template <typename T>
    concept Referee = std::derived_from<T, IReferee>;
  }
}

#endif // #ifndef _CONNECT_X_IREFEREE_HPP_
