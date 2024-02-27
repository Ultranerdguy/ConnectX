#include "ConnectX/Factory.hpp"

struct Build5 : ConnectX::IBuilder<int> {
  virtual char const* GetRegisteredName() const override {
    return "Build5";
  }
  virtual char const* GetArgumentList() const override {
    return "";
  }
  virtual PointerType Create(char const* args) override {
    return std::make_unique<int>(5);
  }
};

int FactoryTester(int argc, char** const argv) {
  ConnectX::Factory<int> intFactory;
  intFactory.Add<Build5>();
  auto pI = intFactory.Create("Build5");

  return (pI && *pI == 5) ? 0 : -1;
}