#include <iostream>

//contains the main component class
#include <api.hpp>

//useful macros, in this case to autogenerate (de)allocator functions
#include <macros.hpp>

#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class TimePrinter final : engine::Component {
public:
  TimePrinter() {}
  ~TimePrinter() {}
  
  //the method called on scene initialization
  void Start() {
    auto rightnow = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto maybenow = std::chrono::system_clock::now();
    auto couldbenow = std::chrono::system_clock::to_time_t(maybenow);
    std::cout << "The current high res time is   " << std::fixed << 0.000001 * (double) rightnow.count() << std::endl;
    std::cout << "The current time is            " << std::fixed << std::ctime(&couldbenow) << std::endl;
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "CurrentTimePrinter"
gencomponent(class TimePrinter, CurrentTimePrinter);
