#ifndef _CONNECT_X_IOCONTROLLER_HPP_
#define _CONNECT_X_IOCONTROLLER_HPP_

#include <iostream>
#include "IController.hpp"

namespace ConnectX {
  class IOController : public IController {
  public:
    IOController(std::istream& input = std::cin, std::ostream& output = std::cout);

    virtual void AssignToken(Token const token) override;
    virtual Vector GetMove(IReferee const& referee, IBoard const& board) override;
    virtual void OnWin() override;
    virtual void OnLose() override;
    virtual void OnDraw() override;
    virtual IController& GetController() override;

  private:
    // Command handlers
    void RunHelp() const;
    void RunPrint(IBoard const& board) const;
    void RunGet(IReferee const& referee, IBoard const& board) const;
    void RunGetToken(IBoard const& board) const;
    void RunGetDimensions(IBoard const& board) const;
    void RunGetStart(IBoard const& board) const;
    void RunGetEnd(IBoard const& board) const;
    void RunGetAt(IBoard const& board) const;
    void RunGetRange(IBoard const& board) const;
    void RunGetHistory(IReferee const& referee) const;

    std::istream& m_input;
    std::ostream& m_output;
    Token m_token{};
  };
}

#endif // #ifndef _CONNECT_X_IOCONTROLLER_HPP_