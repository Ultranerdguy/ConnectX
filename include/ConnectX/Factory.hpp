#ifndef _CONNECT_X_FACTORY_HPP_
#define _CONNECT_X_FACTORY_HPP_

#include <memory>
#include <unordered_map>
#include <string>
#include <concepts>
#include <sstream>

namespace ConnectX
{
  template <typename T>
  struct IBuilder {
    using PointerType = std::unique_ptr<T>;
    virtual char const* GetRegisteredName() const = 0;
    virtual char const* GetArgumentList() const = 0;
    virtual PointerType Create(char const* args) = 0;
  };

  namespace Concept {
    template <typename T, typename U>
    concept Builder = std::derived_from<T,ConnectX::IBuilder<U>>;
  }

  template <typename T>
  class Factory {
  public:
    template <Concept::Builder<T> I, typename ...TArgs>
    void Add(TArgs ...args) {
      auto pBuilder = std::make_unique<I>(args...);
      m_builderMap[pBuilder->GetRegisteredName()] = std::move(pBuilder);
    }
    
    std::string ListAll() {
      std::string output;
      for (auto& [k,v] : m_builderMap) {
        output += v->GetRegisteredName();
        output += " : ";
        output += v->GetArgumentList();
        output += '\n';
      }
      return output;
    }
    
    IBuilder<T>::PointerType Create(char const* args) {
      std::stringstream argStream(args);
      std::string target;
      argStream >> target;
      if (!m_builderMap.contains(target)) {
        return {};
      }
      return m_builderMap[target]->Create(args + target.size());
    }
    
  private:
    std::unordered_map<std::string, std::unique_ptr<IBuilder<T>>> m_builderMap;
  };
}

#endif // #ifndef _CONNECT_X_FACTORY_HPP_
