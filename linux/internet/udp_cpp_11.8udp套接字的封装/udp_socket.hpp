#pragma  once 
#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

class UdpSocket{//用来包装socket
  public:

    UdpSocket()
    :_fd(-1)
    {

    }
    //打开一个udp 的socket
    //返回true 表示创建成功,false  表示失败
    bool Socket(){ 
      _fd =socket(AF_INET,SOCK_DGRAM,0);
      if(_fd<0){
        perror("socket");
        return false;
      }
      return true;
    }

    bool  Close(){ //关闭Socket
      if(_fd!=-1){
        close(_fd);
      }
      return true;
    }
    bool Bind(const std::string& ip,uint16_t port){
      //bind应该和一个ip和端口号向关联
      //需要根据函数构造一个sockaddr_in 结构
      //调用 bind  
      sockaddr_in  addr;
      addr.sin_family=AF_INET;//指定协议IPV4
      addr.sin_addr.s_addr=inet_addr(ip.c_str());//指定ip
      addr.sin_port=htons(port);
      int ret=bind(_fd,(sockaddr*)&addr,sizeof(addr));
      if(ret<0){
        perror("bind");
        return false;
      }
      return true;
    }
    //除了成功失败,还需要返回
    //1.读到的数据
    //2.对方的ip地址
    //3.对方的 端口号
    bool RecvFrom(std::string* msg,std::string* ip=NULL,
        uint16_t* port=NULL){
      char buf[1024*10]={0};
      sockaddr_in peer;
      socklen_t len=sizeof(peer);
      ssize_t n=recvfrom(_fd,buf,sizeof(buf)-1,0,
          (sockaddr*)&peer,&len);
      if(n<0){
        perror("recvfrom");
        return false;
      }
      *msg=buf; 
      //msg->assign(buf); //两者本质上一样
      if(ip!=NULL){
        *ip =inet_ntoa(peer.sin_addr);
      }
      if(port!=NULL){
        *port=ntohs(peer.sin_port);
      }
      return true;
    }

    bool SendTo(const std::string& msg,
        const std::string& ip,uint16_t port){
          sockaddr_in addr;
          addr.sin_family=AF_INET;
          addr.sin_addr.s_addr=inet_addr(ip.c_str());
          addr.sin_port=htons(port);
          ssize_t n=sendto(_fd,msg.c_str(),msg.size(),
              0,(sockaddr*)&addr,sizeof(addr));
          if(n<0){
            perror("sendto");
            return false;
            
          }
          return true;
    }

  private:
    int _fd;  //用来表示 socket(本质为文件描述符)  
};



