#pragma once 
#include"udp_socket.hpp"

//客户端的封装

class UdpClient{
public:
  UdpClient(const std::string& ip,uint16_t port)
  :_server_ip(ip)
   ,_server_port(port)
  {
      _sock.Socket();
  }
  ~UdpClient(){
    _sock.Close();
  }
  //接受服务器端的响应内容
  bool RecvFrom(std::string *msg){
    return _sock.RecvFrom(msg);
  }

  //向服务器发送请求
  bool Sendto(const std::string& msg){
    return _sock.SendTo(msg,_server_ip,_server_port); 
  }
private:
  UdpSocket _sock; //udp版本的socket文件描述符
  std::string _server_ip;  //服务器的IP地址
  uint16_t _server_port;   //服务器的端口号
};
