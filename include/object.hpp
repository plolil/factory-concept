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
      //initialize all our info
      name = new std::string(cstrify(xmlGetProp(node, xmlify("name"))));
      id = new std::string(cstrify(xmlGetProp(node, xmlify("id"))));
      Loader = LoaderPtr;

      //prep all the values
      Components = new complist();
      std::vector<xmlNodePtr> *ComponentNodes = FindNode::ByName(node, "Component");

      //loop through all this object's <Component> children. generate a new instance of engine::Component based on the text between the tags.
      //TODO: add whitespace stripping, so that the system doesn't care about how you format the component name
      for_each(ComponentNodes->begin(), ComponentNodes->end(), [this](xmlNodePtr target) {
	  const char* name = cstrify(target->children->content);
	  //std::cout << name << std::endl;
	  this->Components->push_back(Loader->GetInstance(name));
	});
    }

    //simple member function to run the start method of all components
    void StartAll() {
      for_each(Components->begin(), Components->end(), [](std::shared_ptr<Component> c){
	  c->Start();
	});
    }
  };
}
