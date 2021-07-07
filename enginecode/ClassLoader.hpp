#pragma once

#include <main.hpp>
#include <dlfcn.h>

namespace dloader {

  template <class T>
  class IDLoader {
    
  public:
    virtual ~IDLoader() = default;

    virtual void OpenLib() = 0;

    virtual std::shared_ptr<T>	GetInstance() = 0;
    
    virtual void CloseLib() = 0;
    
  };

  template <class T>
  class CompLoader : public IDLoader<T> {

  private:
    void                *_handle;
    std::string		_pathToLib;

  public:
    CompLoader( std::string const &pathToLib ) :
       _handle(nullptr),
       _pathToLib(pathToLib)
    {}

    ~CompLoader() = default;

    void OpenLib() override {
      if ( !( _handle = dlopen( _pathToLib.c_str(), RTLD_NOW | RTLD_LAZY ) ) ) {
	      std::cerr << dlerror() << std::endl;
      }
    }

    std::shared_ptr<T> GetInstance(std::string Allocator) override
    {
      using allocClass = T *(*)();

      auto allocFunc = reinterpret_cast<allocClass>(dlsym(_handle, Allocator.c_str()));

      if (!allocFunc) {
	CloseLib();
	std::cerr << dlerror() << std::endl;
      }

      return std::shared_ptr<T>(allocFunc(),
				[](T *p){ delete p; });
    }

    void CloseLib() override
    {
      if (dlclose(_handle) != 0) {
	std::cerr << dlerror() << std::endl;
      }
    }

  };
}
