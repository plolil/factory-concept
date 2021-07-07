#pragma once
#include "main.hpp"

#define gencomponent(type, name); extern "C" { type *name() { return new type(); } }
