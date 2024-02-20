# Structure

## Class Diagram
The class structure is designed through interfaces to allow for implementers to create their own completely custom implementations of controllers, boards and even rulesets.
```mermaid
classDiagram
direction TB
class Game {
  -IController[] players
  -IReferee ruleset
  -IBoard board
  +RunGame() IController
  +AddPlayer(in IController newplayer, in ...args)
  +SetReferee(in IReferee newReferee)
  +SetBoard(in IBoard newBoard)
}
Game *-- "*" IController
Game *-- IReferee
Game *-- IBoard

namespace Interfaces {
  class IController
  class IReferee
  class IBoard
  class INotify
}


class IController {
  <<interface>>
  +AssignToken(in const Token token)*
  +GetMove(in const IBoard board) Vector*
  +OnWin()*
  +OnLose()*
  +OnDraw()*
} 

class IReferee {
  <<interface>>
  +Init(in IController[] players, in IBoard board)*
  +GetCurrentPlayer() IController*
  +PlayGame() IController**
}

class IBoard {
  <<interface>>
  +GetScale() Vector*
  +GetAt(in const Vector position) Token*
  +SetAt(in constVector position, in const Token token)*
  +GetRange(in const Vector offset, in const Vector size) TokenBuffer*
}

note for INotify "For event callbacks. Currently<br/>not implemented, but proposed."
class INotify {
  <<interface>>
  +OnStartGame()*
  +OnStartTurn(in const IController player)*
  +OnEndTurn(int const IController player)*
  +OnEndGame()*
}

namespace Proxies {
  class ControllerProxy
  class RefereeProxy
  class BoardProxy
}

IController <|.. ControllerProxy
IController --o ControllerProxy : Reference
class ControllerProxy {
  IController& target
}

IReferee <|.. RefereeProxy
IReferee --o RefereeProxy : Reference
class RefereeProxy {
  IReferee& target
}

IBoard <|.. BoardProxy
IBoard --o BoardProxy : Reference
class BoardProxy {
  IBoard& target
}
```
The `Game` object takes ownership of the interfaces passed in. By combining this with proxy interface implementations, we can allow for optional ownership of the true interface target without compromising on the ownership design.

## Sequence Diagram
```mermaid
sequenceDiagram
  participant Game
  Note over Game: Start of program
  Note over Game: Program calls Game to add<br/>interface implementations<br/>to the Game object
  create participant IReferee
  Game->>IReferee: Create referee
  create participant IController
  Game->>IController: Create player
  create participant IBoard
  Game->>IBoard: Create board
  
  Note over Game,IBoard: Initialisation done, start playing
  IReferee->>IController: On Start game
  loop while game running
    Note over IController,IReferee: Start of IController's turn<br/>as dictated by IReferee
    IReferee->>IController: On Start turn
    loop while no valid move
      IReferee->>IController: Query move
      IController->>IBoard: Query state
      IBoard->>IController: Return state
      IController->>IReferee: Return move
      IReferee->>IBoard: Query move validity
      IBoard->>IReferee: Return move validity
    end
    IReferee->>IBoard: Make move
    IReferee->>IController: On End turn
    IReferee->>IBoard: Query winner state
    IBoard->>IReferee: Return winner state
    alt Has a winner
      IReferee->>IController: On Win/On Lose
      IReferee->>Game: Stop game running
    end
    
    Note over Game: Game over
  end
```
Note: Query-Return pairs in the diagram can be implemented as source calling a method on the target, but are flexible enough to be used with networking (e.g. GET requests).