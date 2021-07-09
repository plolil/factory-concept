#pragma once

#include <memory>
#include <vector>

namespace engine {
  class Component {
  public:
    //the name used to load the component
    std::string* name;
    
    Component() {};
    ~Component() {};

    //virtual methods for making code go brrrr.
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
  };
}
