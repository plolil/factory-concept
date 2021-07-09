#include <iostream>

//contains the main component class
#include <component.hpp>

//useful macros, in this case to autogenerate (de)allocator functions
#include <macros.hpp>

#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class HelloPrinter final : engine::Component {
public:
  HelloPrinter() {}
  ~HelloPrinter() {}
  
  //the method called on scene initialization
  void Start() {
    std::cout << "Hello from line " << __FILE__ << ":" << __LINE__ << ", in function " << __FUNCTION__ << "." << std::endl;
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "CurrentTimePrinter"
gencomponent(class HelloPrinter, HelloPrinter);
