#include"udp_socket.hpp"

class UdpClient{
  public:
    UdpClient(const std::string &ip,const uint16_t &port)
    :_server_ip(ip)
     ,_server_port(port)
    {
      _sock.Socket();
    }

    ~UdpClient(){
      _sock.Close();
    }

    bool RecvFrom( std::string *msg){
      return _sock.RecvFrom(msg);
    }

    bool SendTo(const std::string& msg){
      return _sock.SendTo(msg,_server_ip,_server_port);
    }
  private:
    UdpSocket _sock; //udp版本的文件描述符
    std::string _server_ip;   //服务器ip地址
    uint16_t _server_port;  //服务器端口号
};
