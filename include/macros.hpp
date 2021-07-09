#pragma once
//#include "main.hpp"

//concatenate 2 literals
#define litcat(a, b) a ## b
//generate (de)allocator functions for any class
#define gencomponent(type, name); extern "C" { type * name () { return new type(); } void litcat(name, dealloc) ( type *p ) { delete p; } }

//libxml uses a custom char type. it is fundamentally the same as regular cstrings. these macros act as an easy way to convert between the 2 string types.
#define xmlify(a) reinterpret_cast<const xmlChar*>(a)
#define cstrify(a) reinterpret_cast<const char*>(a)
