#pragma once

#include "all.hpp"
#include <engine/object.hpp>
#include <engine/scene.hpp>

#include <string>
#include <vector>
#include <queue>

namespace engine {
  namespace implementation {
    struct api : engine::api::api {
      api(engine::Scene*);
      engine::api::Object* getParent();
      engine::api::Component* getSelf();
      engine::api::Scene* getScene();
      std::string recieveMessage(long n = 1);
      long getMessageCount();
    private:
      static std::vector<engine::implementation::Object>* objects;
      static engine::implementation::Scene* sceneptr;
      std::queue<std::string>* MessageQueue;
    };
  }
}
