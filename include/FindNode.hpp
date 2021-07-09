#pragma once
#include <libxml/parser.h>
#include <vector>

//grab the 'something="anotherthing"' attributes
struct FindAttr {
  static xmlChar* ByName(xmlNodePtr node, const xmlChar* name) {
    return xmlGetProp(node, name);
  }
  
  static xmlChar* ByName(xmlNodePtr node, const char* name) {
    return ByName(node, reinterpret_cast<const xmlChar*>(name));
  }
};

//get nodes by properties. I don't feel like explaining this. pretty much i just loop through and grab what matches.
struct FindNode {
  static std::vector<xmlNodePtr>* ByName(xmlNodePtr parent, const xmlChar* name) {
    xmlNodePtr cur = parent->children;
    std::vector<xmlNodePtr> *matches = new std::vector<xmlNodePtr> ();
    while (cur != NULL) {
      if (!xmlStrcmp(cur->name, name)) {
	matches->push_back(cur);
      }
      cur=cur->next;
    }
    return matches;
  }
  
  static std::vector<xmlNodePtr>* ByName(xmlNodePtr parent, const char* name) {
    return ByName(parent, reinterpret_cast<const xmlChar*>(name));
  }

  static xmlNodePtr ByID(xmlNodePtr parent, const xmlChar* value) {
    xmlNodePtr cur = parent->children;
    xmlNodePtr match = NULL;
    while (cur != NULL) {
      xmlChar* currentid = FindAttr::ByName(cur, "id");
      
      if (currentid != NULL) {
	if (!xmlStrcmp(currentid, value)) {
	  match = cur;
	  xmlFree(currentid);
	  break;
	}
	xmlFree(currentid);
      }
      
      cur=cur->next;
    }
    return match;
  }
  
  static xmlNodePtr ByID(xmlNodePtr parent, const char* name) {
    return ByID(parent, reinterpret_cast<const xmlChar*>(name));
  }
};
