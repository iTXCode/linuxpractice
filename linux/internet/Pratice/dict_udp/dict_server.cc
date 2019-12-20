
#include<unordered_map>
#include"udp_server.hpp"
#include<iostream>
#include<stdlib.h>


/*
std::unordered_map<std::string,std::string> g_dict;
//无序,

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
*/



int main(){
  std::unordered_map<std::string,std::string> dict;
  dict.insert(std::make_pair("bit","比特"));
  dict.insert(std::make_pair("hello","你好"));
  dict.insert(std::make_pair("jun","筠"));
  dict.insert(std::make_pair("map","地图"));
  dict.insert(std::make_pair("dictory","字典"));

  UdpServer server;
  //lambda 表达式的 [] 中可以写东西
  //把lambda 外部的变量 "捕获" 到lambda 表达式里面
  //捕获可以按照值捕获或用引用捕获
  server.Start("0.0.0.0",9090,[&dict](const std::string& req,
  std::string* resp){
  auto it=dict.find(req);
  if(it==dict.end()){
    *resp="未找到你要查找的单词!";
  }else{
    *resp=it->second;
  }
  });
  return 0;
}

//27：24

//1.什么样的对象才能放到vector？
//模板:一旦编译出错了,显示的错误信息很多.
//(1):vector中放的对象必须是能够拷贝的
//(2):支持移动语义


//&& 左值引用
//转移构造函数
//体现了 c++ 11的 "移动语义"
/*
Test(test&&){};
*/

/*
什么样的对象能放到list里面(和vector相同)
什么样的对象能放到deque里面(和vector相同)
什么样的对象能放到std::array里面(和vector相同)
std::set 中的元素需要满足能拷贝,需要定义一个( operator< )全局函数
std::ma: key value a.key(能拷贝) b.(能比较)  value :能拷贝
std::unordered_map: 
key:  能拷贝  
value  能比较相等  能哈希
*/