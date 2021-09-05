#pragma once

#include "all.hpp"
#include "component.hpp"
#include "object.hpp"
#include "api.hpp"

#include <string>
#include <vector>

namespace engine {
  namespace api {
    struct Scene {
      virtual std::string getFileName();
      virtual std::vector<Object*> getObjects();
      virtual Object* getObjectByID(std::string ID);
    };
  }
}
