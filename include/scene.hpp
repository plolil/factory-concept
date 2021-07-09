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
    //used to get components from lib.so
    dloader::ClassLoader<Component>* Loader;
    //child objects
    std::vector<Object>* Objects;
    //the file this scene is built from
    std::string from;
    //stuff just in case
    xmlNodePtr rootNode;
    xmlNodePtr sceneNode;
    //currently unused
    xmlNodePtr engineNode;
    
    Scene(std::string file) {
      //initialize everything
      from = file;
      xmlDocPtr DP = xmlReadFile( file.c_str(), NULL, 0 );
      rootNode = xmlDocGetRootElement(DP);

      //load the 2 main elements
      engineNode = FindNode::ByName(rootNode, "Engine")->at(0);
      sceneNode  = FindNode::ByName(rootNode, "Scene")->at(0);

      //get all the objects
      std::vector<xmlNodePtr> *ObjectNodes = FindNode::ByName(sceneNode, "Object");

      //ready the component loader
      Loader = new dloader::ClassLoader<Component>("./lib.so");
      Loader->OpenLib();

      //create all objects, passing them their node and this scene's initialized loader
      Objects = new std::vector<Object>();
      for_each(ObjectNodes->begin(), ObjectNodes->end(), [this](xmlNodePtr node) {
	  std::string cname(cstrify(node->name));
	  this->Objects->push_back(Object(node, this->Loader));
	});

      //print out every loaded object, this is just debug
      for_each(Objects->begin(), Objects->end(), [](Object target){std::cout << *target.name << std::endl<< *target.id << std::endl << std::endl;});
    }
  };
}
