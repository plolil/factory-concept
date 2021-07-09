#pragma once

#include <memory>
#include <vector>

namespace engine {
  class Component {
  public:
    
    std::string* name;
    Component() {};
    ~Component() {};
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
  };
}
