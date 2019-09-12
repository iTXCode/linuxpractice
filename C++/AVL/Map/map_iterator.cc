#include<iostream>
#include<string>
#include<map>

void  TestMap(){
  std::map<std::string,std::string> testMap;
  testMap.insert(std::make_pair("China","中国"));
  testMap.insert(std::make_pair("English","英格兰"));
  auto  it=testMap.begin();
  while(it!=testMap.end()){
    std::cout<<it->first<< "--->"<<it->second<<std::endl;
    it++;
  }
}

int main(){
  TestMap();
  return 0;
}
