#ifndef _CONNECT_X_GAME_HPP_
#define _CONNECT_X_GAME_HPP_

#include <vector>
#include <memory>
#include "Types.hpp"
#include "IReferee.hpp"
#include "IBoard.hpp"
#include "IController.hpp"

namespace ConnectX {
  class Game {
  public:
    std::vector<ConnectX::IController*> RunGame();

    template <Concept::Controller TController, typename ...TArgs>
    void AddPlayer(TArgs... args);

    template <Concept::Board TBoard, typename ...TArgs>
    void SetBoard(TArgs... args);

    template <Concept::Referee TReferee, typename ...TArgs>
    void SetReferee(TArgs... args);

  private:
    std::unique_ptr<IReferee> m_referee;
    std::unique_ptr<IBoard> m_board;
    std::vector<std::unique_ptr<IController>> m_players;
  };
}

template <ConnectX::Concept::Controller TController, typename ...TArgs>
void ConnectX::Game::AddPlayer(TArgs... args) {
  m_players.push_back(std::make_unique<TController>(args...));
}

template <ConnectX::Concept::Board TBoard, typename ...TArgs>
void ConnectX::Game::SetBoard(TArgs... args) {
  m_board = std::make_unique<TBoard>(args...);
}

template <ConnectX::Concept::Referee TReferee, typename ...TArgs>
void ConnectX::Game::SetReferee(TArgs... args) {
  m_referee = std::make_unique<TReferee>(args...);
}

#endif // #ifndef _CONNECT_X_GAME_HPP_
