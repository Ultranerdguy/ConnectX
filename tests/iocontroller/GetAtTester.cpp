#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int GetAtTester(int argc, char** const argv) {
  using ConnectX::Equal;
  // Need valid return value at the end to make function return
  std::stringstream input("get at 3,5\n0");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    controller.GetMove(referee, board);
    ConnectX::Token getAtOutput;
    return (output >> getAtOutput) 
      && Equal<ConnectX::Token>(getAtOutput, QueryBoard::at) ? 0 : -1;
  }
  catch (...) {
    // Shouldn't throw any exceptions with valid input
    return -1;
  }
}