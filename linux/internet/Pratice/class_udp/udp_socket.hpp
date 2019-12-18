#pragma once 
#include<cstdio>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<cstring>
#include<string>
#include<arpa/inet.h>

class UdpSocket{
  public:
    UdpSocket()
    :_fd(-1)
    {

    }

    ~UdpSocket(){
    
    }

    bool Socket(){
      _fd=socket(AF_INET,SOCK_DGRAM,0);
      
      if(_fd<0){
        perror("socket");
        return false;
      }
      return true;
    }

    bool Close(){
      if(_fd!=-1){
        close(_fd);
      }
      return true;
    }

    bool Bind(const std::string& ip,uint16_t  port){
      sockaddr_in sock;
      sock.sin_family=AF_INET;
      sock.sin_addr.s_addr=inet_addr(ip.c_str());
      sock.sin_port=htons(port); 
      //htons() 函数将短整型的主机字节序转成网络字节序
      
      int ret=bind(_fd,(sockaddr*)&sock,sizeof(sock));
      
      if(ret<0){
        perror("bind");
        return false;
      }

      return true;
    }

    bool RecvFrom(std::string *msg,std::string* ip=NULL,uint16_t* port=NULL){ 
      char buf[1024]={0};
      sockaddr_in peer;
      socklen_t len=sizeof(peer);
      ssize_t n=recvfrom(_fd,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);
      if(n<0){
        perror("recvfrom");
        return false;
      }
      *msg=buf;

      if(ip!=NULL){
        *ip=inet_ntoa(peer.sin_addr);
      }

      if(port!=NULL){
        *port=ntohs(peer.sin_port);
      }

      return true;
    }

    bool SendTo(const std::string& msg,const std::string ip,
        uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);
      ssize_t n=sendto(_fd,msg.c_str(),msg.size(),0,(sockaddr*)&addr,sizeof(addr));

      if(n<0){
        perror("sendto");
        return false;
      }
      return true;
    }
  private:
    int _fd;//用来表示socket文件描述符
};
