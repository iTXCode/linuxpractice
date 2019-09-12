#include<iostream>
#include<map>
#include<string>
#include<functional>


int main(){
  std::map<int,std::string,std::greater<int>> testMap;
  testMap[8]="中国";
  testMap[2]="美国";
  testMap[1]="武威";
  testMap[3]="甘肃";
  testMap[5]="兰州";
  testMap.insert(std::make_pair(11,"凉州"));
  for(const auto&e:testMap){
    std::cout<<e.first<<" "<<e.second<<std::endl;
  }
  int key;
  std::cin>>key;
  if(testMap.find(key)!=testMap.end()){
    std::cout<<testMap[key]<<std::endl;
  }
  return 0;
}
