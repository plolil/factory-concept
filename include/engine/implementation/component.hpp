#pragma once

#include "all.hpp"

#include <string>
#include <memory>

namespace engine {
  namespace implementation {
    struct Component : engine::api::Component {
      Component(std::shared_ptr<engine::Component>);
      void sendMessage(std::string);
      std::shared_ptr<engine::Component> getRawComponent();
    };
  }
}
