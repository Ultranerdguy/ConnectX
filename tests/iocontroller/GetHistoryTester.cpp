#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int GetHistoryTester(int argc, char** const argv) {
  // Need valid return value at the end to make function return
  std::stringstream input("get history\n0");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    controller.GetMove(referee, board);
    return (output.str() == QueryReferee::expectedHistory) ? 0 : -1;
    return -1;
  }
  catch (...) {
    // Shouldn't throw any exceptions with valid input
    return -1;
  }
}