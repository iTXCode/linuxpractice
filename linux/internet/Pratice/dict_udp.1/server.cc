#include"udp_server.hpp"
#include<iostream>
#include<stdlib.h>
#include<unordered_map>

int main(){
  std::unordered_map<std::string,std::string> dict;
  dict.insert(std::make_pair("jun","筠筠"));
  dict.insert(std::make_pair("hello","你好")); 
  dict.insert(std::make_pair("bit","比特"));
  dict.insert(std::make_pair("world","世界"));
  dict.insert(std::make_pair("name","姓名")); 
  dict.insert(std::make_pair("old","老的"));

  UdpServer server;
  server.Start("0.0.0.0",9090,[&dict](const std::string& req,std::string* resp){
      auto it=dict.find(req);
      if(it==dict.end()){
      *resp="未找到你要查找的单词!\n";
      }else{
      *resp=it->second;
      }
      });
  return 0;
}
