#pragma once
#include "macros.hpp"

#include <vector>
#include <memory>

namespace engine {
class Component;
class Object;
}

typedef std::vector<std::shared_ptr<engine::Component>> complist;

#include "FindNode.hpp"
#include "component.hpp"
#include "object.hpp"

#include <iostream>
