#include"tcp_server.hpp"
#include<unordered_map>

int main(){
  std::unordered_map<std::string,std::string>dict;
  dict.insert(std::make_pair("hello","你好"));
  dict.insert(std::make_pair("bit","比特"));
  dict.insert(std::make_pair("byte","字节"));
  dict.insert(std::make_pair("jun","筠"));
  dict.insert(std::make_pair("map","地图"));
  TcpServer server;
  server.Start("0.0.0.0",9090,[&dict](const std::string &req,std::string *resp){
      auto it=dict.find(req);
      if(it==dict.end()){
      *resp="未找到你所查找的内容!\n";
      }else{
      *resp=it->second;
      }
      });
  return 0;
}
