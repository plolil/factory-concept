#pragma once

#include <string>
#include <api/api.hpp>

namespace engine {
  class Component {
  public:
    //the internal api, unique to each component.
    engine::api::api* api;
    
    //the name used to load the component
    std::string* name;
    
    Component() {};
    ~Component() {};

    //virtual methods for making code go brrrr.
    virtual void Start() = 0;
    virtual void Update(float deltaTime) = 0;
  };
}
