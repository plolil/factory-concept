#include <libxml/parser.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <engine/scene.hpp>

int main( int argc, char ** argv ) {

  // create a new scene, loaded from main.xml
  engine::Scene main("main.xml");

  //loop through each object in the scene, run the start method on all components of each.
  for_each(main.Objects->begin(), main.Objects->end(), [](engine::Object target) {
      std::cout << std::endl << *target.name << std::endl;
      target.StartAll();
    });

  return 0;
}
