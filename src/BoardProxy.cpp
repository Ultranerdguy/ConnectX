#include "ConnectX/BoardProxy.hpp"

ConnectX::BoardProxy::BoardProxy(ConnectX::IBoard& board)
  : m_board(board)
{
}

ConnectX::Vector ConnectX::BoardProxy::GetStart() const {
  return m_board.GetStart();
}

ConnectX::SizeVector ConnectX::BoardProxy::GetSize() const {
  return m_board.GetSize();
}

ConnectX::Token ConnectX::BoardProxy::GetAt(ConnectX::Vector const& position) const {
  return m_board.GetAt(position);
}

void ConnectX::BoardProxy::SetAt(ConnectX::Vector const& position, ConnectX::Token const token) {
  m_board.SetAt(position, token);
}

ConnectX::TokenBuffer ConnectX::BoardProxy::GetRange(ConnectX::Vector const& start, ConnectX::SizeVector const& size) const {
  return m_board.GetRange(start, size);
}

