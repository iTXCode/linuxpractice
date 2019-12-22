#pragma once 

#include"tcp_socket.hpp"
#include<functional>

#define   CHECK_RET(exp) if(!(exp)){\
  return false;\
}

typedef std::function<void(const std::string&,std::string *)> Handler; 

class TcpServer{
  public:
    TcpServer(){}

    bool Start(const std::string& ip,uint16_t port,Handler handler){
      //1.创建一个socket 文件描述符
      CHECK_RET(_listen_sock.Socket());
      //2.绑定端口号
      CHECK_RET(_listen_sock.Bind(ip,port));  
      //3.进行监听
      CHECK_RET(_listen_sock.Listen());

      printf("Server start ok!\n");

      //4.进驻主循环
      while(true){
        
        //5.通过accept获取内核队缓冲区队列中要与服务器建立连接的第一个sokcet文件描述符
        TcpSocket client_sock; 
        std::string ip;
        uint16_t port;
        bool ret=_listen_sock.Accept(&client_sock,&ip,&port);

        if(!ret){
          continue;  //没有获取成功则处于阻塞状态,一直等到与服务器连接的一个socket文件描述符
        }

        printf("[%s]:[%d] 有客户端连接!\n",ip.c_str(),port); //打印日志,提示已经与服务器连接的主机的IP地址

        while(true){
          //1.读取请求
          std::string req;
          int r=client_sock.Recv(&req);

          if(r<0){
            continue;
          }


          if(r==0){
            //对端关闭了连接
            client_sock.Close();
            printf("[%s:%d] 对端关闭了连接!\n",ip.c_str(),port);
            break;
          }

          printf("[%s:%d]对服务器发送:%s\n",ip.c_str(),port,req.c_str());

          std::string resp;
          handler(req,&resp);
          printf("resp:%s\n",resp.c_str());

          //3.将响应的内容返回给客户端
          client_sock.Send(resp);
        }
      }
    }
  private:
    TcpSocket  _listen_sock;
};
