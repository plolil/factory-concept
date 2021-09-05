#pragma once

#include <engine/component.hpp>

#include "all.hpp"
#include "object.hpp"
#include "scene.hpp"
#include "api.hpp"

#include <string>
#include <memory>

namespace engine {
  namespace api {
    struct Component {
      virtual void sendMessage(std::string message);
      virtual std::shared_ptr<engine::Component> getRawComponent();
    };
  }
}
