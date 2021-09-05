#include <engine/implementation/api.hpp>

namespace engine {
  namespace implementation {
    engine::api::Scene* api::getScene() {
      return reinterpret_cast<engine::api::Scene*>(sceneptr);   
    }
  }
}
