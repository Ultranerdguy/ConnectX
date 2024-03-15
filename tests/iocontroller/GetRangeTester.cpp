#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int GetRangeTester(int argc, char** const argv) {
  // Need valid return value at the end to make function return
  std::stringstream input("get range 2,4,6 3,5,7\n0");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    auto value = controller.GetMove(referee, board);
    return (output.str() == QueryBoard::expectedRange) ? 0 : -1;
  }
  catch (...) {
    // Shouldn't throw any exceptions with valid input
    return -1;
  }
}