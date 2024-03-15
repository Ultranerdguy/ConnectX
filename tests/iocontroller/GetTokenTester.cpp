#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int GetTokenTester(int argc, char** const argv) {
  using ConnectX::Equal;
  // Need valid return value at the end to make function return
  std::stringstream input("get token\n0");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  ConnectX::Token targetToken = 19;
  controller.AssignToken(targetToken);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    controller.GetMove(referee, board);
    ConnectX::Token token;
    return ((output >> token) && Equal(token, targetToken)) ? 0 : -1;
  }
  catch (...) {
    // Shouldn't throw any exceptions with valid input
    return -1;
  }
}