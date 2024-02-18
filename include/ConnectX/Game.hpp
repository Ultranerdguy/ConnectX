#ifndef _CONNECT_X_GAME_HPP_
#define _CONNECT_X_GAME_HPP_

#include <vector>
#include <memory>
#include "Types.hpp"
#include "Board.hpp"
#include "IController.hpp"

namespace ConnectX
{
  class Game
  {
  public:
    Game(std::size_t const width = 7, std::size_t const height = 6);
    
    template <typename TController, typename ...TArgs>
    void AddPlayer(Token playerID, TArgs... args);
    Token PlayRound();
    Board const& GetBoard() const;

  private:
    struct PlayerTokenPair
    {
      Token token;
      std::unique_ptr<IController> pPlayer;
    };
    Board m_board;
    std::vector<PlayerTokenPair> m_players;
    std::size_t m_currentPlayerIndex = 0;
  };
}

template <typename TController, typename ...TArgs>
void ConnectX::Game::AddPlayer(ConnectX::Token playerID, TArgs... args)
{
  m_players.push_back({playerID, std::make_unique<TController>(args...)});
}

#endif // #ifndef _CONNECT_X_GAME_HPP_
