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
     //TCP/UDP都是在内核中实现的,
     //操作系统可以同时处理多个连接,所以在内核中有一个队列
     //用于存放已经建立好的连接,listen函数的参数二backlog就指的是这个队列的长度
     //而队列中的元素相当于一个类或者结构体其中包含了(源ip,源端口,目的端口,协议)等信息
    //listen 进入监听状态
    //所谓的" 连接" 指的是一个五元组
    //源ip,源端口,目的端口,协议
    int ret=listen(_fd,10);  
    //有连接的服务,listen将socket先变成被动的socket(服务器专用的socket)
    //等待别人和它建立连接

   
    //参数二:描述的是内核中连接队列的长度
    if(ret<0){
      perror("listen");
      return false;
    }
    return true;
  }
  
/*
所谓的 "链接" 指的是一个五元组：
源ip，源端口，目的IP ，目的端口，协议
*/

  //给服务器使用
  bool Accept(TcpSocket* peer,std::string* ip=NULL,uint16_t* port =NULL){
    //accept 从连接队列中取一个连接到用户代码中
    //如果队列中没有连接,就会阻塞(默认行为)
    sockaddr_in peer_addr;
    socklen_t len=sizeof(peer_addr);
    //返回值也是一个 socket 
    int client_sock=accept(_fd,(sockaddr*)&peer_addr,&len);//len为输入输出参数
    //一旦调用了accept之后后续的操作都有client_sock和操作系统来完成
    //外场将客户拉来之后就让内场来处理
    if(client_sock<0){
      perror("accept");
      return false;
    }

    peer->_fd=client_sock;  //将需要返回的文件描述符交给对端去处理
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
  int Recv(std::string *msg) {
    //括号后面的const 修饰this指针
    msg->clear(); //先将存储返回消息的空间清空
    char buf[1024*10]={0};
    ssize_t n=recv(_fd,buf,sizeof(buf)-1,0); //最后 一个参数位flag
    //recv的返回值,如果读取成功，返回结果为读到的字节数
    //如果读取失败,返回结果为-1
    //如果对端关闭了 socket  返回结果为 0
    if(n<0){
      perror("recv");
      return -1;
    }else if(n==0){
      //需要考虑返回0的情况
      return 0; //0不算是失败
    }
    msg->assign(buf); //赋值操作
    return 1;
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

