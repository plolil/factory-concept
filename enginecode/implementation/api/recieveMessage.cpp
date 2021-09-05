#include <engine/implementation/api.hpp>

namespace engine {
  namespace implementation {
    std::string api::recieveMessage(long n) {
      std::string tmp = MessageQueue->front();
      MessageQueue->pop();
      return tmp;
    }
  }
}
