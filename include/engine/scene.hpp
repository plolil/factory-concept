#pragma once
#include <libxml/parser.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <engine/main.hpp>
#include <engine/object.hpp>
#include <FindNode.hpp>
#include <ClassLoader.hpp>

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
    
    Scene(std::string file);
  };
}
