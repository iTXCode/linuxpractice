#pragma once 

#include<cstdio>
#include<string>
#include<sys/socket.h>
#include<unistd.h>//用于close函数,关闭文件描述符
#include<cstring>
#include<netinet/in.h>  //sockaddr_in 结构体  inet_addr
#include<arpa/inet.h>


class UdpSocket{
  public:
    UdpSocket()
      :_fd(-1)
    {}

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

    bool Bind(const std::string& ip,uint16_t port){
      
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);  //htons() 函数将短整型的主机字节序转成网络字节序
      int ret=bind(_fd,(sockaddr*)& addr,sizeof(addr));
      
      if(ret<0){
        perror("bind");
        return false;
      }
      return true;
    }


    //接受请求/响应
    bool RecvFrom(std::string *msg,std::string* ip=NULL,uint16_t *port=NULL){
      char buf[1024]={0};
      sockaddr_in peer;
      socklen_t len=sizeof(peer);
      ssize_t n=recvfrom(_fd,buf,sizeof(buf)-1,0,(sockaddr*)& peer,&len);

      if(n<0){
        perror("recvfrom");
          return false;
      }

      *msg=buf;
      //将请求内容/响应内容复制给需要计算内容

      if(ip!=NULL){
        *ip=inet_ntoa(peer.sin_addr);
      }

      if(port!=NULL){
        *port=ntohs(peer.sin_port);
      }
      return true;
    }

    bool SendTo(const std::string& msg,const std::string ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);

      ssize_t  ret=sendto(_fd,msg.c_str(),msg.size(),0,(sockaddr*)&addr,sizeof(addr));

      if(ret<0){
        perror("sendto");
        return false;
      }

      return true;
    }
  private:
    int _fd;
};


