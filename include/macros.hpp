#pragma once
//#include "main.hpp"

#define litcat(a, b) a ## b
#define gencomponent(type, name); extern "C" { type * name () { return new type(); } void * litcat(name, dealloc) ( type *p ) { delete p; } }

#define xmlify(a) reinterpret_cast<const xmlChar*>(a)
#define cstrify(a) reinterpret_cast<const char*>(a)
