#include "ConnectX/Types.hpp"

template <>
bool ConnectX::Equal<ConnectX::SingleMove>(ConnectX::SingleMove const& lhs, ConnectX::SingleMove const& rhs) {
  return Equal(lhs.token, rhs.token)
    && Equal(lhs.pController, rhs.pController)
    && Equal(lhs.position, rhs.position);
}