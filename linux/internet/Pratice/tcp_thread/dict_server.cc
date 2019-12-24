#include"tcp_thread_server.hpp"
#include<unordered_map>

int main(){

  std::unordered_map<std::string,std::string> dict;
  dict.insert(std::make_pair("hello","你好"));
  dict.insert(std::make_pair("map","地图"));
  dict.insert(std::make_pair("world","世界"));
  dict.insert(std::make_pair("apple","苹果"));
  dict.insert(std::make_pair("brother","兄弟"));
  dict.insert(std::make_pair("internet","网络"));
  TcpThreadServer server;

  server.Start("0.0.0.0",9090,[&dict](const std::string& req,std::string *resp){
      auto it=dict.find(req);

      if(it==dict.end()){
      *resp="未找到!";
      }else{
      *resp=it->second;
      }
      });

  return 0; 
}
