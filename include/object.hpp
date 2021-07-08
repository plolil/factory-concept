#pragma once
#include "main.hpp"

#include <string>
#include <vector>
#include <memory>
#include <libxml/parser.h>
#include <ClassLoader.hpp>

namespace engine {
  class Object {
  private:
    dloader::ClassLoader<Component>* Loader;
  public:
    std::string *name;
    std::string *id;
    complist *Components;
    Object(xmlNodePtr node,
	   dloader::ClassLoader<Component>* LoaderPtr) {
      name = new std::string(cstrify(xmlGetProp(node, xmlify("name"))));
      
      id = new std::string(cstrify(xmlGetProp(node, xmlify("id"))));

      Components = new complist();
      
    }
  };
}
