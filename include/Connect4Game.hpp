#ifndef _CONNECT_4_GAME_HPP_
#define _CONNECT_4_GAME_HPP_

#include <vector>
#include <memory>
#include "Connect4Types.hpp"
#include "Connect4Board.hpp"
#include "Connect4IController.hpp"

namespace Connect4
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
void Connect4::Game::AddPlayer(Connect4::Token playerID, TArgs... args)
{
  m_players.push_back({playerID, std::make_unique<TController>(args...)});
}

#endif // #ifndef _CONNECT_4_GAME_HPP_
