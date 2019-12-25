//先实现UDP版本的服务器

#include<stdio.h>
#include<sys/socket.h>  //socket所用的头文件
#include<netinet/in.h>  //socketaddr_in 结构体的头文件
#include<arpa/inet.h>   //inet.addr的头文件
#include<cstring>
#include<unistd.h>

int main(){
  //1.先创建一个socket
  // AF_INET是一个宏 ,表示使用 ipv4 协议
  //SOCK_DGRAM   表示使用 UDP 协议
  //第三个参数一般不用
  int sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0){
    //用于查看创建socket是否成功了
    perror("socket");
    return 1;
  }
  //2.把当前的socket  绑定一个ip + 端口号
  sockaddr_in addr;   //争对不同的协议,使用的是一个
  //比较通用的结构体
  addr.sin_family=AF_INET;//指定协议
  addr.sin_addr.s_addr = inet_addr("0.0.0.0"); 

  //0.0.0.0将本地所有的ip都包含进来 
  //数函数inet_addr把点分十进制转换成32位整
  //设置ip地址
  //ip 地址也是一个整数,也需要转成网络字节序,只不过
  //int_addr 函数自动转换了
  addr.sin_port=htons(9090);
  //9090为主机字节序的内容
  //端口号必须得先使用htons函数将主机字节序转成网络字节序
  int ret=bind(sock,(sockaddr*)&addr,sizeof(addr));
  //参数
  //1创建的socket文件描述符sock
  //2.结构体指针(参数需要转换类型)sockaddr
  //3.当前addr结构占用的字节数
  if(ret<0){
    perror("bind");
    return 1;
  }
  

  //端口号启动成功
  printf("server start ok!\n");
  //3.处理服务器收到的请求
  while(true){
    //1.读取客户端的请求
    //面向数据报的函数
    sockaddr_in peer;//表示客户端的ip和端口号
    socklen_t len=sizeof(peer);
    //表示一个整数描述结构体的长度
    //len是一个输入输出参数
    char buf[1024]={0};
    ssize_t n= recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)&peer,&len);
  // recvfrom 面向数据报的函数,为UDP量身定做
  // 返回本次读取的消息长度
  // 参数
  // 1.指定从对应的文件描述符对应的文件中读取数据
  // 2.将网卡中读取到的文件内容存储到内存中
  // 3.缓冲区中有效长度(客户端请求内容的长度)
  // 4.填0就行
  // 5.获取对方的ip和端口号等信息
  // 6.描述结构体 sockaddr_in 的长度
  
   if(n<0){
     perror("recvfrom");
     continue;//考虑到容错,服务器不会因为客户端的一次请求失败就断开与客户的链接
   }
   buf[n]='\0'; //Double check
    //2.根据请求计算响应时间
    //[略]此处写的是一个回显服务器(echo server)
    //3.把响应写回客户端

    n=sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);
  
    if(n<0){
      perror("sendto");
      continue;
    }
    printf("[%s:%d] buf: %s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port), buf);
  }
  //inet_ntoa 把socketaddr 转成点分十进制的字符串结构
  // ntohs 把网络字节序转换成主机字节序
  close(sock);  //关闭socket 文件描述符
  return 0;
}
