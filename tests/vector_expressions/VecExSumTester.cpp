#include "ConnectX/Vector/Vector.hpp"

int VecExSumTester(int argc, char** const argv) {
  using vector = ConnectX::VectorExpression::Vector<int>;

  vector a = {1,2,3};
  vector b = {2,4,6};
  vector expected = {3,6,9};

  return ((a+b) == expected) ? 0 : -1;
}