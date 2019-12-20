#pragma  once 
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

    bool Start(const std::string &ip,uint16_t port,Handler handler){
      bool ret=_sock.Bind(ip,port);

      if(!ret){
        perror("bind");
        return false;
      }

      while(true){
        //读取客户端的请求内容
        std::string req;  //客户端发来的内容
        std::string peer_ip;  //客户端的ip
        uint16_t peer_port;
       _sock.RecvFrom(&req,&peer_ip,&peer_port);
        printf("client req:%s",req.c_str());

        //2.根据请求计算响应
        std::string resp;
        handler(req,&resp);


        //3.将响应内容发送给客户端
        _sock.SendTo(resp,peer_ip,peer_port);
        printf("server resp:%s\n",resp.c_str());
      }
      return true;
    }
  private:
    UdpSocket _sock;
};
