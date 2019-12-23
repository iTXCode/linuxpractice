#pragma once 

#include<wait.h>
#include"tcp_socket.hpp"
#include<functional>
#include<signal.h> 

#define CHECK_RET(exp)   if(!(exp)){\
  return false;\
}

typedef std::function <void(const std::string& ,std::string* )> Handler;

class TcpProcessServer{
public:
  TcpProcessServer(){

  }

  ~TcpProcessServer(){
    _listen_sock.Close();
  }

  bool Start(const std::string& ip,uint16_t port,Handler handler ){
  
    signal(SIGCLD,SIG_IGN);
    //1.创建socket文件描述符
    CHECK_RET(  _listen_sock.Socket() );
    //2.绑定端口和IP
    CHECK_RET(_listen_sock.Bind(ip,port));
    //3.建立监听
    CHECK_RET(_listen_sock.Listen());

    //4.进入循环 
    while(true){
      //5.调用Accept
      TcpSocket client_sock;
      std::string peer_ip;
      uint16_t peer_port;

      bool ret=_listen_sock.Accept(&client_sock,&peer_ip,&peer_port);

      if(!ret){
        continue;  //如果缓冲区中没有待连接的socket文件描述符则阻塞
      }

      printf("[%s:%d] 与服务器建立连接!\n",peer_ip.c_str(),peer_port);

      PrecessConnect(client_sock,peer_ip,peer_port,handler);
    }
    return true;
  }
private:
  TcpSocket _listen_sock;

  void PrecessConnect(TcpSocket& client_sock,const std::string& ip,uint16_t port,Handler handler){
    pid_t ret=fork();

    if(ret>0){
      //父进程
      client_sock.Close();
      return; 
    }

    //3.子进程循环的做下面的事情
    //a.读取客户请求
    while(true){
      std::string req;
      int r=client_sock.Recv(&req);

      if(r<0){
        continue;
      }

      if(r==0){
        printf("[%s:%d] 客户端断开连接!\n",ip.c_str(),port);
        break;  //r==0 表明客户端断开与服务器的连接
      }

      printf("[%s:%d] 客户端发送了 %s\n",ip.c_str(),port,req.c_str());
      //走到这里说明已经从listen所监听的缓冲队列中拿到了将要交互的socket文件描述符
      
       // b.根据请求计算响应,
      std::string resp;
      handler(req,&resp);

      //c.把响应写回客户端
      
      client_sock.Send(resp);
    }

    //子进程的收尾工作
    //1.关闭socket
    client_sock.Close();
    //2.结束进程
    exit(0);
  }
};
