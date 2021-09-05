#include <engine/implementation/api.hpp>

namespace engine {
  namespace implementation {
    long api::getMessageCount() {
      return MessageQueue->size();   
    }
  }
}
