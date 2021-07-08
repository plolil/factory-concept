#pragma once
#include <main.hpp>

#include <memory>
#include <vector>

namespace engine {
  class Component {
  public:
    std::string* name;
    Component() {};
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
  };
  
  typedef std::vector<std::shared_ptr<Component>> complist;
}
