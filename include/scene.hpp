#include <libxml/parser.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <FindNode.hpp>
#include <ClassLoader.hpp>

namespace engine{

  class Scene {

    Scene() {
      //initialize everything
      xmlDocPtr DP = xmlReadFile( "main.xml", NULL, 0 );
      xmlNodePtr root = xmlDocGetRootElement(DP);
      
      xmlNodePtr Engine = FindNode::ByName(root, "Engine")->at(0);
      xmlNodePtr Scene  = FindNode::ByName(root, "Scene")->at(0);
      
      std::vector<xmlNodePtr> *ObjectNodes = FindNode::ByName(Scene, "Object");
      
      std::vector<std::shared_ptr<Component>>* Components = new std::vector<std::shared_ptr<Component>>;
      
      dloader::ClassLoader<Component>* Loader = new dloader::ClassLoader<Component>("./lib.so");
      //  std::cout << "ayyy it loaded!" << std::endl;
      
      std::vector<engine::Object> *Objects = new std::vector<engine::Object>();
      
      for_each(ObjectNodes->begin(), ObjectNodes->end(), [Objects, Loader](xmlNodePtr node) {
	  std::string cname(cstrify(node->name));
	  std::cout << cname << std::endl;
	  //auto Instance = Loader->GetInstance(cname);
	  //Components->push_back(Instance);
	});
    }
  };
}
