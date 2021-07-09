#pragma once

#include <main.hpp>

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
	   dloader::ClassLoader<Component>* LoaderPtr) {
      name = new std::string(cstrify(xmlGetProp(node, xmlify("name"))));
      id = new std::string(cstrify(xmlGetProp(node, xmlify("id"))));
      Loader = LoaderPtr;
      
      Components = new complist();
      std::vector<xmlNodePtr> *ComponentNodes = FindNode::ByName(node, "Component");

      for_each(ComponentNodes->begin(), ComponentNodes->end(), [this](xmlNodePtr target) {
	  const char* name = cstrify(target->children->content);
	  //std::cout << name << std::endl;
	  this->Components->push_back(Loader->GetInstance(name));
	});
    }
    void StartAll() {
      for_each(Components->begin(), Components->end(), [](std::shared_ptr<Component> c){
	  c->Start();
	});
    }
  };
}
