#include <iostream>

//contains everything components need to run
#include <api.hpp>


#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class DataHolder final : engine::Component {
public:
  DataHolder() {}
  ~DataHolder() {}
  
  //the method called on scene initialization
  void Start() {
    std::cout << "Hello from line " << __FILE__ << ":" << __LINE__ << ", in function " << __FUNCTION__ << "." << std::endl;
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "DataHolder"
gencomponent(class DataHolder, DataHolder);
