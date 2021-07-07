#include <libxml/parser.h>
#include <fstream>

#include <main.hpp>

#include "open.hpp"

int main( int argc, char ** argv ) {

  //initialize everything
  xmlParserCtxtPtr currentscene = xmlNewParserCtxt();
  xmlDocPtr DP = xmlCtxtReadFile( currentscene, "main.xml", NULL, 0 );

  std::cout << xmlNodeGetContent(xmlDocGetRootElement(DP)) << std::endl;
  
  return 0;
}
