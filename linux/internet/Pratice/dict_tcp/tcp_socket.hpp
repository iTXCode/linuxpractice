#pragma once 
#include<cstdio>
#include<sys/socket.h>
#include<string>
#include<cstring>
#include<unistd.h>
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

    bool Close(){
      if(_fd!=-1){
        close(_fd);
      }
      return true;
    }

    bool Bind(const std::string &ip,uint16_t port){
      sockaddr_in  addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.s_addr=inet_addr(ip.c_str());
      addr.sin_port=htons(port);
      int  ret=bind(_fd,(sockaddr*)& addr,sizeof(addr));

      if(ret<0){
        perror("bind");
        return false;
      }
      return true;
    }

    bool Listen(){
      int ret= listen(_fd,10);

     //调用格式：int listen(SOCKET s,int backlog);
    //函数功能:本函数仅适用于支持连接的套接字,在Internet通信域,
    //仅用于流式套接字,并仅用于服务器端
    //参数s:服务器端的套接字,一般以先行绑定到熟知的服务器端口,要通过它监听
    //来自客户端的连接请求,一般将这个套接字成为监听套接字
    //参数backlog:指定监听套接字的等待连接缓冲区队列的最大长度,一般设为5
      if(ret<0){
        perror("listen");
        return false; 
      }
      return true;
    }
    
    bool Accept(TcpSocket* peer,std::string *ip=NULL,uint16_t* port=NULL){
      sockaddr_in peer_addr;
      socklen_t len=sizeof(peer_addr);
      int client_sock=accept(_fd,(sockaddr*)& peer_addr,&len);
    
    // 调用格式:SOCKET accept(SOCKET s,struct sockaddr* addr,int* addrlen);
    //函数功能:本函数用于从监听套接字s的等待队列中抽取第一个连接请求
    //创建一个与s同类的新的套接口,来与请求连接的客户机套接字创建连接通道,
    //如果创建成功,就返回新创建的套接字描述符,以后就通过这个新创建的描述符与客户端套接字
    //交互数据
    //如果队列中没有等待的连接请求,并且监听套接字采用非阻塞工作方式,则accept()阻塞
    //调用它的进程,直到新的连接请求出现

    //参数说明:
    //参数s:服务器端监听套接口描述符,调用listen()后,该套接口一直在监听连接
    //参数addr:可选参数,指向sockaddr结构的指针,该结构用来接收下面通信层所知的请求连接
    //一方的套接字的网络地址
    //参数addrlen:可选参数,指向整型数的指针,用来返回addr地址的长度

    //返回值:如果正确执行,返回一个socket类型的描述符
    //否则,返回INVALID_SOCKET错误
      if(client_sock<0){
        perror("accept");
        return false; 
      }

      peer->_fd=client_sock; 
      if(ip!=NULL){
        *ip=inet_ntoa(peer_addr.sin_addr);
      }

      if(port!=NULL){
        *port=ntohs(peer_addr.sin_port);
      }
      return true;
    }

    int Recv(std::string *msg){
      msg->clear(); //先将用于存储返回消息的空间清空

      char buf[1024]={0};
      ssize_t n=recv(_fd,buf,sizeof(buf)-1,0);

      //调用格式: int recv(SOCKET s,char* buf,int len,int flags);
      //函数功能:s是接收端,既调用本函数一方所创建的本地套接字,可以是数据报套接字
      //或者是流式套接字,它已经与对方建立了TCP连接,该套接字的数据接收缓冲区中存有对方
      //发来的数据,调用recv()函数就是要将本地套接字数据缓冲区中的数据接收到用户进程的缓
      //冲区中

      //参数说明
      //参数s:套接字描述符,标识一个接收端已经与对方建立连接的套接字
      //参数buf:用于接收数据的字符缓冲区指针,这个缓冲区是用户进程的接收缓冲区
      //参数len:用户缓冲区长度,以字节大小计算
      //参数flags:指定函数调用方式,一般设置为0
      

      //返回值:如果正确执行,返回从套接字s实际读入到buf中的字节数,
      //连接终端:返回0
      //否则返回SOCKET_ERROE
      if(n<0){
        perror("recv");
        return -1;
      }else if(n==0){
        return 0;
      }

      msg->assign(buf);  //值拷贝
      return 1;
    }


    bool Send(const std::string& msg){
      ssize_t n=send(_fd,msg.c_str(),msg.size(),0);

      //调用格式:int send(SOCKET s,char* buf,int len, int flags);
      //函数功能:send()函数用于向本地已建立连接的数据报或流式套接字发送数据
      //返回值:如果执行正确,返回实际发送出去的数据的字节总数,要注意这个数字可能小于len中
      //所规定的大小,否则,返回SOCKET_ERROR错误

      //参数说明:
      //参数s:SOCKET描述符,标识发送方已经与对方建立连接的套接口,就是要借助连接从
      //这个套接口向外发送数据
      //参数buf:指向用户进程的字符缓冲区的指针,该缓冲区包含要发送的数据
      //参数len:用户缓冲区中数据的长度,以字节计算
      //参数flags:执行此调用的方式,一般置为0
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

      //调用格式:int connect(SOCKET s,struct sockaddr*name,int namelen);
      //函数功能:本函数用于客户端请求与服务器建立连接

      //返回值:若执行正确,返回0
      //否则返回SOCKET_ERROE错误

      //参数说明
      //参数s:SOKCET类型的描述符,标识一个客户端的未连接的套接字
      //参数name:指向sockaddr结构的指针,该结构指定服务器方监听套接字的网络地址
      //,就是要向该套接字请求连接
      //参数namelen:网络地址结构的长度
      if(ret<0){
        perror("connect");
        return false;
      }
      return true;
    }
  private:
    int _fd;
};
