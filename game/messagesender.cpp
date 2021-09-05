#include <iostream>

//contains everything components need to run
#include <api.hpp>


#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class MessageSender final : engine::Component {
public:
  MessageSender() {}
  ~MessageSender() {}
  
  //the method called on scene initialization
  void Start() {
    std::cout << "Hello from line " << __FILE__ << ":" << __LINE__ << ", in function " << __FUNCTION__ << "." << std::endl;
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "MessageSender"
gencomponent(class MessageSender, MessageSender);
