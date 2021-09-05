#pragma once

#include "all.hpp"

#include <string>

namespace engine {
  namespace implementation {
    struct Object : engine::api::Object {
      engine::api::Component* getComponent(std::string);
    };
  }
}
