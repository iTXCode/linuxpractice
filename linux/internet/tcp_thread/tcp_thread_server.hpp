//多线程版本的客户/主机端链接


/*
头文件包含顺序
1.C 标准库
2.c++标准库
3.操作系统提供的标准库
4.第三方库
5.本项目中的文件
*/
#pragma once 
#include"tcp_socket.hpp"
#include<functional>
#include<pthread.h>

#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void (const std::string&,std::string*)>Handler;

class TcpThreadServer{
public:
  TcpThreadServer(){
   
  }
  ~TcpThreadServer(){
    _listen_sock.Close();
  }

  bool Start(const std::string &ip,uint16_t port,
      Handler handler){
    //1.创建 socket 
    CHECK_RET(_listen_sock.Socket());
    //2.绑定端口
    CHECK_RET(_listen_sock.Bind(ip,port));
    //3，监听
    CHECK_RET(_listen_sock.Listen());
    //4.进入主循环
    while(true){ 
      //5.调用 accept
      TcpSocket client_sock;
      std::string peer_ip;
      uint16_t  peer_port;
      bool ret=_listen_sock.Accept(&client_sock,&peer_ip,
          &peer_port);
      if(!ret){
        continue; 
    }
      printf("[%s:%d] 客户端建立链接!\n",peer_ip.c_str(),
          peer_port);
    //6.创建线程出路客户端的逻辑
    ProcessConnect(client_sock,peer_ip,
        peer_port,handler);
   }
}
private:
  TcpSocket _listen_sock;
  struct ThreadEntryArg{
    TcpSocket client_sock;
    std::string ip;
    uint16_t port;
    Handler  handler;
  };
  void ProcessConnect(TcpSocket& client_sock,
      const std::string& ip,uint16_t port,Handler handler ){
    //1.创建线程
    pthread_t tid; 
    ThreadEntryArg *arg=new ThreadEntryArg;
    arg->client_sock=client_sock;
    arg->ip =ip;
    arg->port=port;
    arg->handler = handler;
    pthread_create(&tid,NULL,ThreadEntry,(void*)arg);
    //2.对于主线程来说,让函数立刻返回
    pthread_detach(tid);
    //3.对于新线程来说,循环处理客户端的操作
      
  }
static void *ThreadEntry(void* arg){
  ThreadEntryArg* argument= (ThreadEntryArg*)arg;
  TcpSocket& client_sock = argument->client_sock;
  std::string& ip=argument->ip;
  uint16_t port=argument->port;
  Handler handler=argument->handler;
  while(true){
    //      a.读取客户端请求
    std::string req;
    int ret=client_sock.Recv(&req);
    if(ret<0){
      continue;
    }
    if(ret==0){
      client_sock.Close();
      printf("[%s:%d] 客户端断开链接！\n",
          ip.c_str(),port);
      break;
    }
    //      b.根据请求计算响应
    printf("[%s:%d ] 客户端请求 %s\n",ip.c_str(),
        port,req.c_str());
    std::string resp;
    handler(req,&resp);
    //      c.把响应写回客户端
    client_sock.Send(resp);
  }
  delete  argument;
  return NULL;
}
};
