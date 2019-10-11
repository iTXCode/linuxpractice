#pragma once

#include"tcp_socket.hpp"
//给用户提供的信息越少越好

class TcpClient{
public:
  TcpClient(){
    _sock.Socket();
  }
  ~TcpClient(){
    _sock.Close();
  }

  bool Connect(const std::string &ip,uint16_t port){
    return _sock.Connect(ip,port);
  }

  int Recv(std::string *msg){
    return _sock.Recv(msg);
  }

  bool Send(const std::string&msg){
    return _sock.Send(msg);
  }
private:
  TcpSocket _sock;
};
