#pragma once

#include "all.hpp"
#include "component.hpp"
#include "object.hpp"
#include "scene.hpp"

#include <string>

namespace engine {
  namespace api {
    struct api {
      virtual Object* getParent() = 0;
      virtual Component* getSelf() = 0;
      virtual Scene* getScene() = 0;
      virtual std::string recieveMessage(long) = 0;
      virtual long getMessageCount() = 0;
    };
  }
}
