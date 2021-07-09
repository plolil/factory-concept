#include <iostream>
#include <component.hpp>
#include <macros.hpp>

#include <chrono>

class HelloPrinter final : engine::Component {
public:
  HelloPrinter() {}
  ~HelloPrinter() {}
  void Start() {
    auto rightnow = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto maybenow = std::chrono::system_clock::now();
    auto couldbenow = std::chrono::system_clock::to_time_t(maybenow);
    std::cout << "The current high res time is   " << std::fixed << 0.000001 * (double) rightnow.count() << std::endl;
    std::cout << "The current time is            " << std::fixed << std::ctime(&couldbenow) << std::endl;
  }
  void Update(float deltaTime) {}
};

gencomponent(class HelloPrinter, HelloWorldPrinter);
