#pragma once
#include<functional>
#include"udp_socket.hpp"
#include<cassert>
//通用的 udp 服务器
//1.读取请求
//2.根据请求计算响应
//3.把响应写回客户端
//其中1和3 是固定套路,不管是啥场景,代码都一样
//2 和业务相关,所以就把 2 对应的代码提取成一个回调函数
//这个回调函数应该是一个


//typedef void (*Handler)(const std::string& req,
//    std::string* resp);

//c++ 11 引入
typedef  std::function<void(const std::string&,
    std::string*)>  Handler;

class UdpServer{
public:
  UdpServer( ){
  assert(_sock.Socket());
  }

  ~UdpServer(){
    _sock.Close();
  }

  bool Start(const std::string& ip,uint16_t port,
      Handler handler){
     //服务器启动的核心步骤
     //1.创建socket(已近完成)
     //2.绑定端口号
     bool ret=_sock.Bind(ip,port);
     if(!ret){
       return false;
     }
     //3.进入一个死循环
     while(true){
       //处理每个请求
       //1.读取请求
      std::string req;
      std::string peer_ip;
      uint16_t peer_port;
       _sock.RecvFrom(&req,&peer_ip,&peer_port);
       //2.根据请求计算响应
       std::string  resp;
       handler(req,&resp);
       //3.把响应返回给客户端
       _sock.SendTo(resp,peer_ip,peer_port);
     }
  }
private:
  UdpSocket  _sock;
};
