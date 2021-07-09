#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <dlfcn.h>

namespace dloader {

  template <class T>
  class IDLoader {
    
  public:
    virtual ~IDLoader() = default;

    virtual void OpenLib() = 0;

    virtual std::shared_ptr<T>	GetInstance(std::string Allocator) = 0;
    
    virtual void CloseLib() = 0;
    
  };

  template <class T>
  class ClassLoader : public IDLoader<T> {

  private:
    void                *_handle;
    std::string		_pathToLib;

  public:
    ClassLoader( std::string const &pathToLib ) :
       _handle(nullptr),
       _pathToLib(pathToLib)
    {}

    ~ClassLoader() = default;

    void OpenLib() override {
      if ( !( _handle = dlopen( _pathToLib.c_str(), RTLD_NOW | RTLD_LAZY ) ) ) {
	std::cerr << dlerror() << __LINE__ << std::endl;
      }
    }

    std::shared_ptr<T> GetInstance(std::string Allocator) override
    {
      using allocClass = T *(*)();
      using deallocClass = void (*)(T*);
      
      std::string deallocator = Allocator + "dealloc";

      auto allocFunc = reinterpret_cast<allocClass>(dlsym(_handle, Allocator.c_str()));
      auto deallocFunc = reinterpret_cast<deallocClass>(dlsym(_handle, deallocator.c_str()));
      //std::cout << "(de)allocator function attempted" << std::endl;

      if (!allocFunc || !deallocFunc) {
	CloseLib();
	std::cerr << dlerror()  << __LINE__<< std::endl;
      }

      return std::shared_ptr<T>(allocFunc(), deallocFunc);
    }

    void CloseLib() override
    {
      if (dlclose(_handle) != 0) {
	std::cerr << dlerror() << __LINE__ << std::endl;
      }
    }

  };
}
