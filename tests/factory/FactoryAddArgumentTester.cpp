#include "ConnectX/Factory.hpp"

struct BuildAny : ConnectX::IBuilder<int> {
  BuildAny(int value)
    : m_value{value}
  {
  }
  virtual char const* GetRegisteredName() const override {
    return "BuildAny";
  }
  virtual char const* GetArgumentList() const override {
    return "";
  }
  virtual PointerType Create(char const* args) override {
    return std::make_unique<int>(m_value);
  }

  int m_value{}; // value to build
};

int FactoryAddArgumentTester(int argc, char** const argv) {
  constexpr int buildValue = 7;
  ConnectX::Factory<int> intFactory;
  intFactory.Add<BuildAny>(buildValue);
  auto pI = intFactory.Create("BuildAny");

  return (pI && *pI == buildValue) ? 0 : -1;
}