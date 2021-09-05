#pragma once

#include "all.hpp"
#include "component.hpp"
#include "scene.hpp"
#include "api.hpp"

#include <string>

namespace engine {
  namespace api {
    struct Object {
      virtual std::string getID();
      virtual Component* getComponent(std::string id);
    };
  }
}
