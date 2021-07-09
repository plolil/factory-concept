#include <libxml/parser.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>

#include <FindNode.hpp>
#include <ClassLoader.hpp>
#include <scene.hpp>

int main( int argc, char ** argv ) {

  engine::Scene main("main.xml");
  main.Objects->at(0).StartAll();
  /*
  std::cout << cstrify(FindNode::ByName(FindNode::ByID(Scene, "threeprinters"), "Component")->at(0)->children->content) << std::endl;
  */
  return 0;
}
