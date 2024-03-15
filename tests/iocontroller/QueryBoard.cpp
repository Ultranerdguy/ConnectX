#include "QueryBoard.hpp"

ConnectX::Vector QueryBoard::start = {2,4,6};
ConnectX::Vector QueryBoard::end = {3,5,7};
ConnectX::Token QueryBoard::at = 8;
ConnectX::TokenBuffer QueryBoard::range = {9,8,7,6,5,4,3,2};

ConnectX::Vector QueryBoard::GetStart() const {
  return start;
}

ConnectX::Vector QueryBoard::GetEnd() const {
  return end;
}

ConnectX::Token QueryBoard::GetAt(ConnectX::Vector const& position) const {
  return at;
}

void QueryBoard::SetAt(ConnectX::Vector const& position, ConnectX::Token const token) {
  return;
}

ConnectX::TokenBuffer QueryBoard::GetRange(ConnectX::Vector const& start, ConnectX::Vector const& end) const {
  return range;
}
