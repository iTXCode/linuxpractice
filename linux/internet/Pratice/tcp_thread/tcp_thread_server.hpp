#pragma once 



#include"tcp_socket.hpp"
#include<pthread.h>
#include<functional>

typedef std::function <void(const std::string&,std::string*)> Handler;

#define CHECK_RET(exp) if(!(exp)){\
return false;\
}


class TcpThreadServer{
  public:
    TcpThreadServer(){}

    ~TcpThreadServer(){
      _listen_sock.Close();
    }

    bool  Start(const std::string &ip,uint16_t port,Handler handler){
      //1.产生文件描述符
      CHECK_RET( _listen_sock.Socket() );
      //2.绑定端口号
      CHECK_RET(_listen_sock.Bind(ip,port));
      //3.进行监听
      CHECK_RET(_listen_sock.Listen());
      
      //4.进入主循环
      while(true){
        //做调用前的准备
        TcpSocket client_sock;
        std::string peer_ip;
        uint16_t peer_port;
         //5.调用accept
        bool ret=_listen_sock.Accept(&client_sock,&peer_ip,&peer_port);

        if(!ret){
          continue;
        }

       printf("[%s:%d] 建立连接!\n",peer_ip.c_str(),peer_port);
      //6.创建线程出路客户端的逻辑
      //让调用者在外面无法知道该类中的的实现方式
      ThreadConnect(client_sock,peer_ip,peer_port,handler);
      
    }
   }
  private:
    TcpSocket _listen_sock;
  
    struct TheadEntryArg{
      TcpSocket client_sock;
      std::string ip;
      uint16_t port;
      Handler handler; 
    };
    void ThreadConnect(TcpSocket &client_sock,const std::string& ip,uint16_t port,Handler handler){
      pthread_t tid;

      TheadEntryArg  *arg=new TheadEntryArg;
      arg->client_sock=client_sock;
      arg->ip=ip;
      arg->port=port;
      arg->handler=handler;

      pthread_create(&tid,NULL,ThreadEntry,(void*)arg);

      //3.对于新线程来说,循环处理客户端的操作
      
      pthread_detach(tid);

    }

    static void* ThreadEntry(void *arg){
      //这里加上static 
      //说明这个函数是一个普通函数,只不过它在类的内部而已
      //做为返回仅限于类内部
      
      TheadEntryArg *argument=(TheadEntryArg* ) arg;
      TcpSocket& client_sock=argument->client_sock;
      std::string& ip=argument->ip;
      uint16_t port=argument->port;
      Handler handler=argument->handler;

      while(true){
        //a.读取客户端的请求
        std::string req;
        int ret=client_sock.Recv(&req);
        
        if(ret<0){
          continue;
        }

        if(ret==0){
          client_sock.Close();
          printf("[%s:%d] 客户端断开连接!\n",ip.c_str(),port);
          break; 
        }

        //b.根据请求计算响应
        
        printf("[%s:%d] req:%s\n",ip.c_str(),port,req.c_str());
        std::string resp;
        
        
        handler(req,&resp);

        // c.把响应写回客户端
        client_sock.Send(resp);
      }
      delete argument; 
      //释放堆上的空间
      return NULL;
    }
    
};
