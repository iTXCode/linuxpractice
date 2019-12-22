#pragma once 

#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

class TcpSocket{
  public:
    TcpSocket()
    :_fd(-1)
    {

    }

    bool Socket(){
      _fd=socket(AF_INET,SOCK_STREAM,0);
      
      if(_fd<0){
        perror("socket");
        return false;
      }
      return true;
    }

    bool Bind(const std::string &ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);

      int ret=bind(_fd,(sockaddr*)& addr,sizeof(addr));

      if(ret<0){
        perror("bind");
        return false;
      }
      return true;
    }

    bool Listen(){
      int ret=listen(_fd,10);

      if(ret<0){
        perror("listen");
        return false;
      }
      return true;
    }
 
    bool Accept(TcpSocket* peer,std::string* ip=NULL,uint16_t*  port=NULL){
      sockaddr_in addr;
      socklen_t len=sizeof(addr);
      int client_sock=accept(_fd,(sockaddr*)& addr,&len);

      if(client_sock<0){
        perror("accept");
        return false;
      }
      
      peer->_fd=client_sock;
      //将需要返回的文件描述交给对端去处理
      if(ip!=NULL){
        *ip=inet_ntoa(addr.sin_addr);
      }

      if(port!=NULL){
        *port=ntohs(addr.sin_port);
      }
      return true;
    }


    int Recv(std::string *msg){
      msg->clear();//清空内寸中可能存在的数据
      char buf[1024]={0};
      ssize_t n=recv(_fd,buf,sizeof(buf)-1,0);

      if(n<0){
        perror("recv");
        return -1;
      }else if(n==0){
        return 0;
      }
     
      msg->assign(buf);
      return 1;
    }

    bool Send(const std::string& msg){
      ssize_t n=send(_fd,msg.c_str(),msg.size(),0);
      if(n<0){
        perror("send");
        return false;
      }
      return true;
    }

    bool Connect(const std::string &ip,uint16_t port){
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);

      int ret=connect(_fd,(sockaddr*)& addr,sizeof(addr));

      if(ret<0){
        perror("connect");
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
  private:
    int _fd;
};
