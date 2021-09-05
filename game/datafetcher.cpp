#include <iostream>

//contains everything components need to run
#include <api.hpp>
#include "dataholder.cpp"

#include <chrono>

//the final keyword stops some compiler warnings. not necessary though.
class DataFetcher final : engine::Component {
public:
  DataFetcher() {}
  ~DataFetcher() {}
  
  //the method called on scene initialization
  void Start() {
    class DataHolder* DH = reinterpret_cast<class DataHolder*>(api->getParent()->getComponent("DataHolder"));
  }
  
  //the method called every frame
  void Update(float deltaTime) {}
};

//generate allocator functions. the name to be used in the XML is "DataFetcher"
gencomponent(class DataFetcher, DataFetcher);
