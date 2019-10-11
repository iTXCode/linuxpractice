#pragma once 
//通用的TCP 服务器
#include"tcp_socket.hpp"
#include<functional>
#define CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void(const std::string&,std::string*)> Handler;

class TcpServer{
public:
  TcpServer(){

  }
  bool Start(const std::string& ip,uint16_t port,
      Handler handler){
    //tcp 启动的基本流程
    //1.先创建一个socket
    CHECK_RET(listen_sock_.Socket());
    //2.绑定端口号
    CHECK_RET(listen_sock_.Bind(ip,port));
    //3.进行监听
    CHECK_RET(listen_sock_.Listen());
    printf("Server start OK\n");
    //4.进入主循环
    while(true){
      //5.通过accept 获取到一个连接
      TcpSocket client_sock; //和客户端沟通的socket
      std::string ip;
      uint16_t port;
      //核心问题在于,第一次Accept 之后就进入了一个循环
      //在这个操作过程中,循环一直没有结束,Accept 没有被重复调用到
      //后续链接过来的客户端都在内核中的链接队列中排队呢,一直得不到处理
      //应该想办法让我们的程序能够更快速的调用到Accept
      //多进程或者多线程解决
      bool ret=listen_sock_.Accept(&client_sock,&ip,&port);
      if(!ret){
        continue;
      }
      printf("[%s:%d] 有客户端连接!\n",ip.c_str(),port );
      //6.和客户端进行具体的沟通,一次连接
      //就进行多次更新
      while(true){
        //1.读取请求
        std::string req;
        int r=client_sock.Recv(&req);
        if(r<0){
          continue;
        }
        if(r==0){
          //对端关闭了 socket 
          client_sock.Close();
          printf("[%s:%d] 对端关闭了连接\n",ip.c_str(),port);
          break;
        }
        printf("[%s:%d] 对客户端发送了:%s\n",ip.c_str(),port,req.c_str());
        //2.根据请求计算响应
        std::string resp;
        handler(req,&resp);
        //3.把响应写回到客户端
        client_sock.Send(resp);
      }
      
    }
  }
private:
  TcpSocket listen_sock_;
};
