#pragma once 


#include<cstdio>
#include<string>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>



class TcpSocket{
  public:
    TcpSocket()
    :_fd(-1)
    {}

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
      addr.sin_port=htons(port);
      addr.sin_addr.s_addr=inet_addr(ip.c_str());

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


    bool Accept(TcpSocket* peer,std::string* ip=NULL,uint16_t* port=NULL){
     sockaddr_in peer_addr;
     socklen_t len=sizeof(peer_addr);
     int client_sock=accept(_fd,(sockaddr*)& peer_addr,&len);

     if(client_sock<0){
       perror("accept");
       return false;
     }

     peer->_fd=client_sock; //将从缓冲区取出的文件描述符交给对端处理 

     if(ip!=NULL){
       *ip=inet_ntoa(peer_addr.sin_addr);
     }

     if(port!=NULL){
       *port=ntohs(peer_addr.sin_port);
     }
      return true;
    }



    bool Recv(std::string *msg){
      msg->clear();
      char buf[1024*10]={0};

      int ret=recv(_fd,buf,sizeof(buf)-1,0);

      if(ret<0){
        perror("recv");
        return -1;
      }else if(ret==0){
        return 0;
      }

      msg->assign(buf);
      return true;
    }

    bool Send(const std::string &msg){
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
