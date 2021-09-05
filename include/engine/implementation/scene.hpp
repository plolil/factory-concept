#pragma once

#include "all.hpp"
#include <engine/scene.hpp>

#include <string>
#include <vector>

namespace engine {
  namespace implementation {
    struct Scene : engine::api::Scene {
      Scene(engine::Scene*);
      std::string getFileName();
      std::vector<engine::api::Object*> getObjects();
      engine::api::Object* getObjectByID(std::string);
    };
  }
}
