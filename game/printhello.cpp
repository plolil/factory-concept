#include <iostream>
#include <main.hpp>

class HelloPrinter : engine::Component {
public:
  void Start() {
    std::cout << "Hello, World!";
  }
  void Update(float deltaTime) {}
};

gencomponent(class HelloPrinter, HelloWorldPrinter);
