#pragma once
#include "main.hpp"

#define gencomponent(type, name); extern "C" { type *name() { return new type(); } }

#define xmlify(a) reinterpret_cast<const xmlChar*>(a)
#define cstrify(a) reinterpret_cast<const char*>(a)
