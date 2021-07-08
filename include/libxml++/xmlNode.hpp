#pragma once

#include <libxml/parser.h>

namespace xml {
  class Node {
  private:
    xmlNodePtr np;
  public:
    Node(xmlNodePtr ptr) : np(ptr) {};

    xmlNodePtr getStruct() {return np;}
    
    Node operator=(Node tocopy) {
      if (this == &tocopy) {
	return *this;
      }
      np = xmlCopyNode(tocopy.getStruct(), 1);
      return *this;
    }
  };
}
