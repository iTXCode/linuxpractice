#pragma once  

#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;

class UdpSocket{
  UdpSocket()
  :_sock(-1)
  {

  }

  bool Socket(){
    _sock=socket(AF_INET,SOCK_DGRAM,0);
    if(_sock<0){
      perror("socket!");
      return false; 
    }
    return true;
  }

  bool Close(){
    if(_sock!=-1){  
      close(_sock); 
    }
    return true;
  }

  bool Bind(const string& ip,uint16_t port){
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    //此函数中的参数类型是cpp风格的字符串,
    //与c语言风格的字符串还是有一定差别的
    //所以我们需要经cpp类型的字符串转成c风格类型的
    //字符串
    int ret=bind(_sock,(sockaddr*)& addr,sizeof(addr));
    if(ret<0){
      perror("bind!");
      return false;
    }
    return true;
  }
  
  //除了成功和失败之外,还需要返回什么?
  //1.得到的数据
  //2.对方的IP
  //3.对方的端口号
  //客户端调用接口时不关注对端的IP和端口号，所以将其置为空
  bool ResvFrom(string* msg,string* ip=nullptr,uint16_t* port=nullptr){
    
    char buf[1024*10]={0};
    sockaddr_in peer;
    peer.sin_family=AF_INET;
    socklen_t len=sizeof(peer);
    ssize_t n=recvfrom(_sock,buf,sizeof(buf)-1,0,
        (sockaddr*)& peer,&len);
    if(n<0){
      perror("recvfrom!");
      return false;
    }
    buf[n]='\0';
    *msg=buf;
    if(ip!=nullptr){
      *ip=inet_ntoa(peer.sin_addr);
    }
    if(port!=nullptr){
      *port=ntohs(peer.sin_port);
    }
    return true;
  }

  bool SendTo(const string& msg,const string& ip,
      uint16_t port){
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    addr.sin_port=htons(port);
    ssize_t n=sendto(_sock,msg.c_str(),msg.size(),0,
        (sockaddr*)& addr,sizeof(addr));
    if(n<0){
      perror("sendto!");
      return false;
    } 
    return true; 
  }

  private:
    int _sock; 
};
