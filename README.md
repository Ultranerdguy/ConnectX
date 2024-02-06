# ConnectX

An implementation of Connect4, written in C++, designed to be customizable.

Roadmap:
- Refactor player interface
- Rethink the token data type (possibly templated to allow for user defined information, e.g. colour, icon etc)
- Refactor board into an interface
- Refactor the rules of the game into an interface
- Rebuild the default board into a dense board (every cell stored in memory)
- Implement the default rules of connect4 into a ruleset
- Create a sparse board (empty cells not stored, maybe some run length encoding) for storing *really* large boards
- ???
