#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int ReturnTester(int argc, char** const argv) {
  std::stringstream input("return 0,1,2");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    auto value = controller.GetMove(referee, board);
    return (value[0] == 0)
      && (value[1] == 1)
      && (value[2] == 2) ? 0 : -1;
  }
  catch (...) {
    // Shouldn't throw any exceptions with valid input
    return -1;
  }
}