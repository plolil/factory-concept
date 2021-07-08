#pragma once

#include <libxml/parser.h>
#include "xmlNode.hpp"

namespace xml {
  class Doc {
  private:
    xmlDocPtr dp;
  public:
    Doc(xmlDocPtr ptr) : dp(ptr) {}
    Doc(const xmlChar * cur, 
	const char * URL, 
	const char * encoding, 
	int options) {
      dp = xmlReadDoc(cur, URL, encoding, options);
    }
    Doc(int fd, 
	const char * URL, 
	const char * encoding, 
	int options) {
      dp = xmlReadFd(fd, URL, encoding, options);
    }
    Doc(const char * filename,
	const char * encoding, 
	int options) {
      dp = xmlReadFile(filename, encoding, options);
    }

    /**
     *Returns the core xmlDocPtr that this class wraps
     */
    xmlDocPtr getStruct() {return dp;}

    /**
     *Do a copy of the node to a given document.
     */
    Node* copyNode(Node node, bool extended) {
      return new Node(xmlDocCopyNode(node.getStruct(), dp, extended));
    }

    /**
     *Dump an XML document to an open FILE.
     */
    int dump (FILE *f) {
      return xmlDocDump(f, dp);
    }

    /**
     *Get the root element of the document (doc->children is a list containing possibly comments, PIs, etc ...).
     */
    Node* getRootElement() {
      return new Node(xmlDocGetRootElement(dp));
    }

    /**
     *Set the root element of the document (doc->children is a list containing possibly comments, PIs, etc ...).
     */
    Node* setRootElement(Node root) {
      return new Node(xmlDocSetRootElement(dp, root.getStruct()));
    }

    /**
     *
     */

    /**
     *
     */

    Doc operator=(Doc tocopy) {
      if (this == &tocopy) {
	return *this;
      }
      dp = xmlCopyDoc(tocopy.getStruct(), 1);
      return *this;
    }
  };
}
