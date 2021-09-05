#include <iostream>

//contains everything components need to run
#include <api.hpp>


#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class MessageGetter final : engine::Component {
public:
  MessageGetter() {}
  ~MessageGetter() {}
  
  //the method called on scene initialization
  void Start() {
    std::cout << "Hello from line " << __FILE__ << ":" << __LINE__ << ", in function " << __FUNCTION__ << "." << std::endl;
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "MessageGetter"
gencomponent(class MessageGetter, MessageGetter);
