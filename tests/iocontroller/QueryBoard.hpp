#ifndef _CONNECT_X_TEST_QUERY_BOARD_HPP_
#define _CONNECT_X_TEST_QUERY_BOARD_HPP_

#include "ConnectX/IBoard.hpp"

class QueryBoard : public ConnectX::IBoard {
public:
  static ConnectX::Vector start;
  static ConnectX::Vector end;
  static ConnectX::Token at;
  static ConnectX::TokenBuffer range;
  static constexpr char expectedRange[] = "\
8 | 6\n\
9 | 7\n\
\n\
4 | 2\n\
5 | 3\n\
\n";

  virtual ConnectX::Vector GetStart() const override;
  virtual ConnectX::Vector GetEnd() const override;
  virtual ConnectX::Token GetAt(ConnectX::Vector const& position) const override;
  virtual void SetAt(ConnectX::Vector const& position, ConnectX::Token const token) override;
  virtual ConnectX::TokenBuffer GetRange(ConnectX::Vector const& start, ConnectX::Vector const& end) const override;
};

#endif // #ifndef _CONNECT_X_TEST_QUERY_BOARD_HPP_