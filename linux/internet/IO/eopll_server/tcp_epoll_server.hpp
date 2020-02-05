#pragma once 

#include"tcp_socket.hpp"
#include<sys/epoll.h>
#include<functional>
#include<vector>


//Epoll 这个类就对标Selector 这个类
class Epoll{
  public:
    Epoll(){
      _epoll_fd=epoll_create(5);
    }

    ~Epoll(){
      close(_epoll_fd);

    }

    void Add(const TcpSocket& sock){
      printf("[Epoll::Add] %d\n",sock.GetFd());
      epoll_event   event;
      event.events=EPOLLIN;
      //此处 epoll add 的时候插入的是键值对
      //fd 在键和值之中都出现了,这件事情是迫不得已(这也是epoll一个小小的槽点)
      
      event.data.fd=sock.GetFd();
      epoll_ctl(_epoll_fd,EPOLL_CTL_ADD,sock.GetFd(),&event);
    }
    
    void Del(const TcpSocket& sock){
      printf("[Epoll::Del] %d\n",sock.GetFd());
      epoll_ctl(_epoll_fd,EPOLL_CTL_DEL,sock.GetFd(),NULL);
    }

    void Wait(std::vector<TcpSocket>* output){
      output->clear();
      //等待文件描述符就绪
     epoll_event events[100];
     //最后一个参数表示阻塞等待
     //返回之后,就有若干个文件描述符就绪,保存在events 数组之中
     //返回值如果就是在描述数组中有几个有效元素
     //epoll_wait 返回的内容只是键值对的值
     //如果不加任何处理的话,用户不知道对应的文件描述符是谁。
     //迫不得已,只能在插入的时候,把socket 往值里也寸一份
     int nfds=epoll_wait(_epoll_fd,events,100,-1);
     if(nfds<0){
       perror("epoll_wait");
       return;
     }

     //依次处理每个就绪的文件描述符
     for(int i=0;i<nfds;++i){
       int sock=events[i].data.fd;
       output->push_back(TcpSocket(sock));
     }
    }
  private:
    int _epoll_fd; //通过这个_epoll_fd 找到内核中的对象,从而进行文件描述符的管理

};

#define CHECK_RET(exp)\
  if(!exp){\
    return false;\
  }

typedef std::function<void(std::string&,std::string*)> Handler;

class TcpEpollServer{
  public:
    bool Start(const std::string& ip,uint16_t port,Handler handler){
      //1.创建socket
      TcpSocket listen_sock;
      CHECK_RET(listen_sock.Socket());
      //2.绑定端口号
      CHECK_RET(listen_sock.Bind(ip,port));
      //3.监听socket
      CHECK_RET(listen_sock.Listen());
      //4.创建Epoll对象，并把listen_sock用Epoll管理起来
      Epoll epoll;
      epoll.Add(listen_sock);
      //5.进入主循环
      while(true){
        //6.使用Epoll::Wait 等待文件描述符就绪
        std::vector<TcpSocket> output;
        epoll.Wait(&output);
        //7.循环处理每个就绪的文件描述符，也是分成两种情况

        for(auto sock:output){

          if(sock.GetFd()==listen_sock.GetFd()){
            // a.listen_sock 就调用Accept
            TcpSocket client_sock;
            sock.Accept(&client_sock);
            epoll.Add(client_sock);
          }else{
            // b.非listen_sock就调用Recv 
            std::string req;

            int n=sock.Recv(&req);
            if(n<0){
              continue;
            }

            if(n==0){
              //对端关闭
              printf("[client_sock %d] disconnected!\n",sock.GetFd());
              sock.Close();
              epoll.Del(sock);
              continue;
            }

            printf("[client %d] %s\n",sock.GetFd(),req.c_str());
            //正确读取的情况
            std::string resp;
            handler(req,&resp);
            sock.Send(resp);
          }//end of else 
          

        }  //end of for 
      }//end of while 
    } //end of Start

};
