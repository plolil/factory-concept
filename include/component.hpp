#pragma once
#include "main.hpp"

namespace engine {
  class Component {
  public:
    Component() {};
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
  };
}
