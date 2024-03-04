# IOController

Allows the user to interface with a board through the use of basic commands.

Note that this specifies the controller to work with IO, not StdIO. With C++ `std::istream`, we can use stdin in the same way as a file, string or any other appropriate implementation of std::istream.

We can also use `std::ostream` for a generic output buffer, instead of just `std::cout`. This allows logging to be written to stdout, a file (for debugging), both or neither.

The implementation for `AssignToken` will just store the token internally.

The implementation for `GetMove` will prompt the user for input via a command system. This will allow the user to view the board, get the last set of moves and make their move.

The implementations for `OnWin`, `OnLose` and `OnDraw` will just print a message to the output stream.

## Commands
- `help` : Prints a simple help message
- `get <command>` : Gets information about the current game
  - `token` : Shows the controller's current token
  - `dimensions` : Prints the number of dimensions of the board
  - `start` : Prints the smallest index of the board
  - `end` : Prints the largest index of the board
  - `<Vector position>`/`at <Vector position>` : Prints the token at `position` in the board. If `position` is out of bounds, prints an error
  - `range <Vector start> <Vector end>` : Prints a chunk of the board. Prints a 2D slice starting from the end of the buffer
  - `history` : Prints all the moves played since this controllers last turn
- `print` : Prints the board. Equivalent to `get start`;`get end`;`get range <start> <end>`
- `return <Vector position>`/`<Vector position>` : Returns the position to the referee

The format of a `Vector` follows the pattern `([0-9]+)(,\s*[0-9]+)*`, effectively a list of comma separated values with optional whitespace after the comma. Any whitespace after a number signifies the end of the `Vector`.

