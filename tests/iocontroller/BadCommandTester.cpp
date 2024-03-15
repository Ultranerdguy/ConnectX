#include <sstream>
#include "ConnectX/IOController.hpp"
#include "QueryReferee.hpp"
#include "QueryBoard.hpp"

int BadCommandTester(int argc, char** const argv) {
  std::stringstream input("this is bad input");
  std::stringstream output;
  QueryBoard board;
  QueryReferee referee;
  ConnectX::IOController controller(input, output);

  // Expect to fail. Input is bad, so shouldn't pass without exceptions
  // All exceptions are good
  try {
    controller.GetMove(referee, board);
    return -1;
  }
  catch (std::ios_base::failure&) {
    return 0;
  }
  catch (...) {
    // Unknown exception, failed test
    return -1;
  }
}