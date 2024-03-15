#include "QueryReferee.hpp"

std::vector<ConnectX::SingleMove> QueryReferee::history = {{3,nullptr,{2,3,4}},{5,nullptr,{7,6,5}}};

void QueryReferee::AddController(ConnectX::IController& controller) {

}

void QueryReferee::SetBoard(ConnectX::IBoard& board) {

}

ConnectX::IController* QueryReferee::GetCurrentController() const {
  return nullptr;
}

std::size_t QueryReferee::GetControllerCount() const {
  return 0;
}

ConnectX::SingleMove QueryReferee::GetHistory(std::size_t const index) const {
  return {};
}

std::vector<ConnectX::SingleMove> QueryReferee::GetHistoryRange(std::size_t const start, std::size_t const size) const {
  return history;
}

std::size_t QueryReferee::GetHistorySize() const {
  return 2;
}

std::vector<ConnectX::IController*> QueryReferee::PlayGame() {
  return {};
}