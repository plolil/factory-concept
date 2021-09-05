#include <engine/implementation/api.hpp>
#include <engine/implementation/scene.hpp>

namespace engine {
  namespace implementation {
    std::vector<engine::implementation::Object>* api::objects = nullptr;
    engine::implementation::Scene* api::sceneptr = nullptr;
    api::api(engine::Scene* initscene) {
      sceneptr = new Scene(initscene);
      MessageQueue = new std::queue<std::string>();
      
    }
  }
}
