#pragma once
#include "macros.hpp"

#include <vector>
#include <memory>

namespace engine {
  class Component;
  class Object;
  struct Scene;
}

typedef std::vector<std::shared_ptr<engine::Component>> complist;

#include "FindNode.hpp"
#include "engine/component.hpp"
#include "engine/object.hpp"
#include "engine/scene.hpp"

#include <iostream>
