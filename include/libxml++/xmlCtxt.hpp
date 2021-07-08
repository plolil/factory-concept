#pragma once

#include <libxml/parser.h>
#include "xmlDoc.hpp"

namespace xml {
  class ParserCtxt {
  private:
    xmlParserCtxtPtr cp;
  public:
    ParserCtxt(const xmlChar * cur) {
      cp = xmlCreateDocParserCtxt(cur);
    }
    ParserCtxt(xmlSAXHandlerPtr sax, 
	       void * user_data, 
	       xmlInputReadCallback ioread, 
	       xmlInputCloseCallback ioclose, 
	       void * ioctx, 
	       xmlCharEncoding enc) {
      cp = xmlCreateIOParserCtxt(sax, user_data, ioread, ioclose, ioctx, enc);
    }
    ParserCtxt(xmlSAXHandlerPtr sax, 
	       void * user_data, 
	       const char * chunk, 
	       int size, 
	       const char * filename) {
      cp = xmlCreatePushParserCtxt(sax, user_data, chunk, size, filename);
    }
    ParserCtxt(xmlParserCtxtPtr ptr) : cp(ptr) {};
    ParserCtxt() {
      cp = xmlNewParserCtxt();
    }
    
    int UseOptions (int options) {
      return xmlCtxtUseOptions(cp, options);
    }

    Doc* ReadDoc(const xmlChar * cur, 
		 const char * URL, 
		 const char * encoding, 
		 int options) {
      return new Doc(xmlCtxtReadDoc(cp, cur, URL, encoding, options));
    }
    
    Doc* ReadFd(int fd, 
		const char * URL, 
		const char * encoding, 
		int options) {
      return new Doc(xmlCtxtReadFd(cp, fd, URL, encoding, options));
    }
    
    Doc* ReadFile(const char * filename, 
		  const char * encoding, 
		  int options) {
      return new Doc(xmlCtxtReadFile(cp, filename, encoding, options));
    }

  };
}
