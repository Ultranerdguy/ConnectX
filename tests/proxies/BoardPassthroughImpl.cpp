#include "BoardPassthroughImpl.hpp"

ConnectX::Vector BoardImpl::valueGetStart = {0,0,0};
ConnectX::Vector BoardImpl::valueGetEnd = {1,2,3};
ConnectX::Token BoardImpl::valueGetAt = 7;
ConnectX::TokenBuffer BoardImpl::valueGetRange = {4,5,6};

BoardImpl::BoardImpl(BoardProxyResults& r)
  : results(r)
{
}

ConnectX::Vector BoardImpl::GetStart() const {
  results.getStart = true;
  return valueGetStart;
}
ConnectX::Vector BoardImpl::GetEnd() const {
  results.getEnd = true;
  return valueGetEnd;
}
ConnectX::Token BoardImpl::GetAt(ConnectX::Vector const& position) const {
  results.getAt = position;
  return valueGetAt;
}
void BoardImpl::SetAt(ConnectX::Vector const& position, ConnectX::Token const token) {
  results.setAt.position = position;
  results.setAt.token = token;
}
ConnectX::TokenBuffer BoardImpl::GetRange(ConnectX::Vector const& start, ConnectX::Vector const& end) const {
  results.getRange.start = start;
  results.getRange.end = end;
  return valueGetRange;
}