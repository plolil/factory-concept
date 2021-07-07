#include <libxml/parser.h>
#include <fstream>

#include <main.hpp>

int main(int argc, char ** argv) {
  xmlParserCtxtPtr currentscene = xmlNewParserCtxt();
  std::fstream CSfile("main.xml", std::fstream::in);
  
  return 0;
}
