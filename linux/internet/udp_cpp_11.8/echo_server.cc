#include"udp_server.hpp"
//void Echo(const std::string& req,std::string* resp){
//  *resp=req;//回显服务器，请求是什么，就返回什么
//}
//
int main(){
  UdpServer server;
  //lambda 表达式 本质上是一个 匿名函数
  //[]()->int {}
  server.Start("0.0.0.0",9090,[](const std::string &req,
        std::string* resp){*resp=req;});
//server.Start("0.0.0.0",9090,Echo);//c++反对函数指针
  return 0;
}
