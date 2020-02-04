#pragma once
#include<vector>
#include<set>
//使用set的原因:1.需要高效的插入和删除。2.需要方便的找到最大元素
#include<functional>
#include<sys/select.h>
#include"tcp_socket.hpp"


//lhs左操作数
//rhs表示右操作数
bool operator<(const TcpSocket& lhs,const TcpSocket& rhs){
  return lhs.GetFd()<rhs.GetFd();
}

//select 这个函数用起来很不方便,所以我们封装成一个类来使用
//提供以下几个操作
//文件描述符的管理器,这个管理器中包含的socket 就是使用select来管理的socket
//1.新增一个文件描述符
//2.删除一个文件描述符
//3.等待操作  等待管理的文件描述符就绪(指考虑就绪的情况)
class Selector{
  public:
    void Add(const TcpSocket& sock){
     printf("[Selector::Add] %d\n",sock.GetFd()); //打印日志
     _socket_set.insert(sock);
    }

    void Del(const TcpSocket& sock){
      printf("[Selector::Del] %d\n",sock.GetFd());
      _socket_set.erase(sock);
    }
    

    void Wait(std::vector<TcpSocket>* output){
      //调用Wait就相当于 调用select 进行等待
      //先获取到最大的文件描述符
      
      if(_socket_set.empty()){
        printf("[Selector::Wait] _socket_set if empty\n");
        return;
      }
      int max_fd=_socket_set.rbegin()->GetFd();
      fd_set readfds;
      FD_ZERO(&readfds);
      //把 set 中的每个需要关注的文件描述符都设置到 readfds 之中
      
      for(const auto& sock:_socket_set){
        FD_SET(sock.GetFd(),&readfds);
      }

      //select 默认使阻塞等待，有文件描述符返回的时候,才能进行返回
      //  当这个函数返回之后,就应该根据文件描述符的返回情况
      //  构造一个输出参数,告诉调用者那些socket 就绪了
      int nfds=select(max_fd+1, &readfds, NULL,NULL,NULL);

      if(nfds<0){
        perror("select");
        return;
      }
      //已经返回了,返回结果同样保存在readfds之中
      
      for(int fd=0;fd<max_fd+1;++fd){
        if(FD_ISSET(fd,&readfds)){
          //如果是,说明当前fd就是读就绪的
          //就把这个结果放到输出结果中
          output->push_back(TcpSocket(fd));
        }
      }
    }

    //wait返回的时候需要告诉调用者那那些文件描述符就绪了
    
  private:

    //使用一个数据结构把我们需要的socket存起来
    //要求TcpSocket类能够支持 比较操作 (operator <)
    std::set<TcpSocket> _socket_set;
};





//实现一个select 版本的TCP server
typedef std::function<void(const std::string&,std::string*)> Handler;

#define CHECK_RET(exp)\
  if(!exp){\
    return false;\
  }

class TcpSelectServer{
  public:
    //一个服务器程序在处理请求的时候典型的流程就是3个 步骤
    //1.读取请求并解析
    //2.根据请求计算响应
    //3.将响应结果写回到客户端
    bool Start(const std::string&ip,uint16_t port,Handler handler){
      //1.创建socket
      TcpSocket listen_sock;
      CHECK_RET( listen_sock.Socket());
      //2.绑定端口号
      CHECK_RET(listen_sock.Bind(ip,port));
      //3.监听文件描述符
      CHECK_RET(listen_sock.Listen());
      //4.先创建一个selector对象，让这个对象先把_listen_sock 管理起来
      //后续进行等待,都是靠selector 对象完成
      Selector Selector;
      Selector.Add(listen_sock);
      //5.进入主循环
      while(true){
        //6.不再是直接调用accept,而是使用selector进行 等待
        std::vector<TcpSocket> output;
        Selector.Wait(&output);
        //7.遍历返回结果,依次处理每个就绪的socket
        
        for(auto tcp_socket : output){
          //8.分成两种情况讨论
     
          if(tcp_socket.GetFd()==listen_sock.GetFd()){
          //a.如果就绪队列 socket 是listen_sock要进行的操作是调用accept      
            TcpSocket client_sock;
            std::string ip;
            uint16_t port;
            tcp_socket.Accept(&client_sock,&ip,&port);
            Selector.Add(client_sock);
            printf("[client %s:%d] connected!\n",ip.c_str(),port);
          }else{ 
            //b.如果就绪的socket不是listen_sock 要进行的操作是调用recv
            std::string req;
            int n=tcp_socket.Recv(&req);

            if(n<0){
              continue;
            }

            if(n==0){
              //对端关闭,同时也要把这个socket 从 Selector 中删掉
              tcp_socket.Close();
              Selector.Del(tcp_socket);
              continue;
            }


            printf("[client] %s\n",req.c_str());
            std::string resp;
            //根据请求计算响应
            handler(req,&resp);
            tcp_socket.Send(resp); 
          }
        }
      }
    }
  private:
};
