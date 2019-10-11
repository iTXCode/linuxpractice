#pragma  once
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
    //和UDP 不同的是,第二个参数面向字节流(TCP)
    _fd=socket(AF_INET,SOCK_STREAM,0);
    if(_fd<0){
      perror("socket");
      return false;
    }
   return true;
  }
  //给服务器使用
  bool Bind(const std::string&ip,uint16_t port){
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    addr.sin_port=htons(port);
    int ret=bind(_fd,(sockaddr*) &addr,sizeof(addr));
    if(ret<0){
      perror("bind");
      return false;
    }
    return true;
  }


  //给服务器使用
  bool Listen(){
    //listen 进入监听状态
    //所谓的" 连接" 指的是一个五元组
    //源ip,源端口,目的端口,协议
    int ret=listen(_fd,10);
    if(ret<0){
      perror("listen");
      return false;
    }
    return true;
  }
  

  //给服务器使用
  bool Accept(TcpSocket* peer,std::string* ip=NULL,uint16_t* port =NULL){
    //accept 从连接队列中取一个连接到用户代码中
    //如果队列中没有连接,就会阻塞(默认行为)
    sockaddr_in peer_addr;
    socklen_t len=sizeof(peer_addr);
    //返回值也是一个 socket 
    int client_sock=accept(_fd,(sockaddr*)&peer_addr,&len);
    if(client_sock<0){
      perror("accept");
      return false;
    }
    peer->_fd=client_sock;
    if(ip!=NULL){
      *ip = inet_ntoa(peer_addr.sin_addr);
      //把peer_addr所包含的IP地址转换成点分十进制
      //交给用户
    }
    if(port!=NULL){
      *port=ntohs(peer_addr.sin_port);
      //把网络序转换成主机序
    }
    return true; 
  }

  //客户端和服务器都会使用
  bool Recv(std::string *msg) {
    //括号后面的const 修饰this指针
    msg->clear();
    char buf[1024*10]={0};
    ssize_t n=recv(_fd,buf,sizeof(buf)-1,0);
    //recv的返回值,如果读取成功，返回结果为读到的字节数
    //如果读取失败,返回结果为-1
    //如果对端关闭了 socket  返回结果为 0
    if(n<0){
      perror("recv");
      return -1;
    }else if(n==0){
      //需要考虑返回0的情况
      return 0;
    }
    msg->assign(buf);
    return true;
  }


  //客户端和服务器都会使用 
  bool Send(const std::string& msg) {
    ssize_t n=send(_fd,msg.c_str(),msg.size(),0);
    if(n<0){
      perror("send");
      return false;
    }
    return true;
  }

  //给客户端使用
  bool Connect(const std::string &ip,uint16_t port){
    sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr(ip.c_str());
    addr.sin_port=htons(port);
    int ret=connect(_fd,(sockaddr*)&addr,sizeof(addr));
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

