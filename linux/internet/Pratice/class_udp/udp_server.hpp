#include"udp_socket.hpp"
#include<assert.h>
#include<functional>


typedef std::function<void(const std::string&,std::string* )> Handler;


class UdpServer{
public:
UdpServer(){
   assert(_sock.Socket());
}

~UdpServer(){
    _sock.Close();
}

bool Start(const std::string& ip,uint16_t port,Handler handler){
  bool ret=_sock.Bind(ip,port); 
  if(!ret){
    return false;
  }


  while(true){

    //读取客户的请求内容
    std::string req;
    std::string peer_ip;
    uint16_t peer_port;
    _sock.RecvFrom(&req,&peer_ip,&peer_port);
    //2.根据请求计算响应
    std::string resp;
    handler(req,&resp);


    //3.将响应结果发送给客户端
    _sock.SendTo(resp,peer_ip,peer_port);
  }
  return true;
}
private:
UdpSocket _sock;
};
