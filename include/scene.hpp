#include <libxml/parser.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <main.hpp>
#include <FindNode.hpp>

namespace engine{

  struct Scene {
    dloader::ClassLoader<Component>* Loader;
    std::vector<Object>* Objects;
    std::string from;
    xmlNodePtr rootNode;
    xmlNodePtr engineNode;
    xmlNodePtr sceneNode;
    
    Scene(std::string file) {
      from = file;
      //initialize everything
      xmlDocPtr DP = xmlReadFile( file.c_str(), NULL, 0 );
      rootNode = xmlDocGetRootElement(DP);
      
      engineNode = FindNode::ByName(rootNode, "Engine")->at(0);
      sceneNode  = FindNode::ByName(rootNode, "Scene")->at(0);
      
      std::vector<xmlNodePtr> *ObjectNodes = FindNode::ByName(sceneNode, "Object");
      
      Loader = new dloader::ClassLoader<Component>("./lib.so");
      Loader->OpenLib();
      
      Objects = new std::vector<Object>();
      
      for_each(ObjectNodes->begin(), ObjectNodes->end(), [this](xmlNodePtr node) {
	  std::string cname(cstrify(node->name));
	  this->Objects->push_back(Object(node, this->Loader));
	});
      for_each(Objects->begin(), Objects->end(), [](Object target){std::cout << *target.name << std::endl<< *target.id << std::endl << std::endl;});
    }
  };
}
