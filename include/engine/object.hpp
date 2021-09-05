#pragma once

#include <engine/main.hpp>

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>
#include <libxml/parser.h>
#include <ClassLoader.hpp>

namespace engine {
  class Object {
  public:
    dloader::ClassLoader<Component>* Loader;
    std::string *name;
    std::string *id;
    complist *Components;
    
    Object(xmlNodePtr node,
	   dloader::ClassLoader<Component>* LoaderPtr);

    //simple member function to run the start method of all components
    void StartAll();
  };
}
