#include "ConnectX/Factory.hpp"

struct BuildVariable : ConnectX::IBuilder<int> {
  virtual char const* GetRegisteredName() const override {
    return "BuildVariable";
  }
  virtual char const* GetArgumentList() const override {
    return "";
  }
  virtual PointerType Create(char const* args) override {
    int value{};
    if (sscanf_s(args, "%d", &value) != 1) {
      return nullptr;
    }
    return std::make_unique<int>(value);
  }
};

int FactoryCreateArgumentTester(int argc, char** const argv) {
  ConnectX::Factory<int> intFactory;
  intFactory.Add<BuildVariable>();
  auto pI = intFactory.Create("BuildVariable 8");

  return (pI && *pI == 8) ? 0 : -1;
}