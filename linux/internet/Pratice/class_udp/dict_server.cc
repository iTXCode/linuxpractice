
#include<unordered_map>
#include"udp_server.hpp"
#include<iostream>
#include<stdlib.h>

std::unordered_map<std::string,std::string> g_dict;

void Translate(const std::string& req,std::string* resp){
  auto it=g_dict.find(req);
  if(it==g_dict.end()){
    *resp="未找到!";
    return;
  }
  *resp=it->second;
}

int  main(int argc,char* argv[]){
  if(argc!=3){
    printf("Usage ./dict_server [ip] [port]\n");
    return 1;
  }

  g_dict.insert(std::make_pair("hello","你好"));
  g_dict.insert(std::make_pair("world","世界"));
  g_dict.insert(std::make_pair("jun","筠"));
  g_dict.insert(std::make_pair("bit","比特"));
  g_dict.insert(std::make_pair("China","中国"));
  UdpServer server;
  server.Start(argv[1],atoi(argv[2]),Translate);
  return 0;
}
